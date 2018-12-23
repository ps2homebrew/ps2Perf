#  _____     ___ ____
#   ____|   |    ____|      PSX2 OpenSource Project
#  |     ___|   |____       (C)2003, Mavy & Bigboss ( mavy@ps2reality.net , 
#						      bigboss@ps2reality.net )
#  ---------------------------------------------------------------------------

EE_BIN_DIR = ../../bin/
EE_INCS += -I../../include/

EE_BIN = $(EE_BIN_DIR)ps2PerfExample.elf
EE_OBJS = main.o 
EE_LIBS += -lps2Perf
EE_LDFLAGS += -L../lib

all: $(EE_BIN_DIR) $(EE_OBJS_DIR) $(EE_BIN)
	mkdir -p $(EE_BIN_DIR)

$(EE_BIN_DIR):
	mkdir -p $(EE_BIN_DIR)

$(EE_OBJS_DIR):
	mkdir -p $(EE_OBJS_DIR)

clean:
	rm -f -r $(EE_OBJS) $(EE_BIN_DIR)

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.eeglobal
#include ../../Makefile.eeglobal
