
#include <tamtypes.h>

#ifndef _IOP_HEAP_H_
#define _IOP_HEAP_H_

int iop_heap_init();
u32 iop_heap_alloc(int size);
int iop_heap_dma_upload(void *src,u32 dst,int size);

#endif
