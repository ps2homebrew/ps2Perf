

#include <stdlib.h>
#include <stdio.h>
#include <tamtypes.h>
#include <sifcmd.h>
#include <kernel.h>
#include <sifrpc.h>



// defines
#define IOPHEAP_BIND_RPC 0x80000003

// iop_heap global rpc variables
static struct t_rpc_client_data iop_heap_sif __attribute__((aligned(64)));
static u8 send_buffer[512] __attribute__((aligned(128)));
static u8 recieve_buffer[512] __attribute__((aligned(128)));

// globals
static int iop_heap_initialised = 0;

// helpers
static void nopdelay()
{
  int i;    
  for (i=0; i<0x10000; i++) {
    asm ( "nop\n nop\n nop\n nop\n nop\n" );
  }
}

static void flush_cache(u64 val)
{
	__asm__ __volatile__("

		daddu			$4,$0,%0
  	addiu			$3,$0,0x64
		syscall		0		
		nop
	"
	:
	:"r"(val)
	:"$3","$4","memory"
	);
}

static u64 sif_dma_stat(u64 hdma)
{
	u64 ret=0;
	u64 *pret = &ret;
	u64 *phdma = &hdma;

	__asm__ __volatile__("

		ld				$4,0(%0)
  	addiu			$3,$0,0x76
		syscall		0		
		nop
		sd			  $2,0(%1)
	"
	:
	:"r"(phdma),"r"(pret)
	:"$2","$3","$4","memory"	
	);
	return ret;
}

static u64 sif_set_dma(void *blk, int cmd)
{
	u64 ret=0;
	u64 *pret = &ret;
	int *pcmd = &cmd;

	__asm__ __volatile__("

		daddu			$4,$0,%0
		lw				$5,0(%1)
  	addiu			$3,$0,0x77
		syscall		0		
		nop
		sd				$2,0(%2)
	"
	:
	:"r"(blk),"r"(pcmd),"r"(pret)
	:"$2","$3","$4","$5","memory"	
	);
	return ret;
}

int iop_heap_init()
{
  if(iop_heap_initialised)
  	return 0;

  iop_heap_sif.server = NULL;
    
  do 
	{
    if (sif_bind_rpc(&iop_heap_sif, IOPHEAP_BIND_RPC, 0) < 0) {
    	return -1;
    }
    nopdelay();
  }
	while(!iop_heap_sif.server);
  
  iop_heap_initialised = 1;

	return 1;
}

u32 iop_heap_alloc(int size)
{
	int i=0,len=0,ret=0;
	u32 adr=0;
  u8  *pkt;
 
  if(!iop_heap_initialised)
  	return 0;
  
  /* build packet */
  pkt = send_buffer; 
  PUSHDATA( int, pkt, size, i);
  pkt += i; len += i;

	if ((ret = sif_call_rpc( &iop_heap_sif, 1, 0, send_buffer, len, recieve_buffer, 4, 0, 0)) < 0)
	  return -1;

  POPDATA( u64, UNCACHED_SEG(recieve_buffer), adr, i);  

  return adr;    
}

int iop_heap_dma_upload(void *src,u32 dst,int size)
{
	int i=0,len=0;
  u8  *pkt;
	u64 ret=0;
	long ret2=0;

	flush_cache(0);

  /* build packet */
  pkt = send_buffer; 
  PUSHDATA( u32, pkt, (u32)src, i);
  pkt += i; len += i;
  PUSHDATA( u32, pkt, dst, i);
  pkt += i; len += i;
  PUSHDATA( int, pkt, size, i);
  pkt += i; len += i;
  PUSHDATA( int, pkt, 0, i);
  pkt += i; len += i;

	ret = sif_set_dma(send_buffer,1);

	while((ret2 = sif_dma_stat(ret))>=0);

	flush_cache(0);

	return (ret2 < -1);
}

