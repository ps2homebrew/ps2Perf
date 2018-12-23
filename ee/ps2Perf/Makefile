#  _____     ___ ____
#   ____|   |    ____|      PSX2 OpenSource Project
#  |     ___|   |____       (C)2003, Mavy & Bigboss ( mavy@ps2reality.net , 
#						      bigboss@ps2reality.net )
#  ---------------------------------------------------------------------------


EE_OBJS_DIR = ../obj/
EE_LIB_DIR = ../lib/
EE_LIB = $(EE_LIB_DIR)libps2Perf.a
EE_OBJS = $(EE_OBJS_DIR)ps2Perf.o
EE_INC = ../../include/
EE_INCS += -I$(EE_INC)

all: $(EE_OBJS_DIR) $(EE_LIB_DIR) $(EE_LIB)

$(EE_OBJS_DIR):
	mkdir -p $(EE_OBJS_DIR)

$(EE_LIB_DIR):
	mkdir -p $(EE_LIB_DIR)

$(EE_OBJS_DIR)%.o : %.c
	$(EE_C_COMPILE) -c $< -o $@

install: all
	mkdir -p $(PS2DEV)/ps2Perf/lib
	cp -f $(EE_LIB) $(PS2DEV)/ps2Perf/lib
	mkdir -p $(PS2DEV)/ps2Perf/include
	cp -f $(EE_INC)ps2Perf.h $(PS2DEV)/ps2Perf/include

clean:
	rm -rf $(EE_OBJS_DIR) $(EE_LIB_DIR)

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.eeglobal
#include ../../Makefile.eeglobal
