#
# Makefile template
# 

PROJECT		= ps2PerfSample
OBJECTS		= main.o sjpcm_rpc.o ps2Perf.o iopheap.o loadmodule.o
		
PREFIX		= ee-
AS		= $(PREFIX)gcc
CC		= $(PREFIX)gcc
LD		= $(PREFIX)gcc
DVPASM		= $(PREFIX)dvp-as
OBJDUMP		= $(PREFIX)objdump
RM		= rm -f

CFLAGS =	-D_EE  -mips3 -mcpu=r5900 -ffreestanding -fnonnull-objects -fno-builtin \
		    -fshort-double -mlong64 -mhard-float -mno-abicalls -O2 -EL 

LDFLAGS =	-Wl,-Map,$(PROJECT).map -L.

# Include settings for ps2lib/newlib
include $(PS2LIB)/ee/Makefile.include

$(PROJECT).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(PROJECT).elf $(OBJECTS) -lc -lkernel -lc -lm

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.s.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.elf *.o *.map 
