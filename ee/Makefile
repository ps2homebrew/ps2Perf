#  _____     ___ ____
#   ____|   |    ____|      PSX2 OpenSource Project
#  |     ___|   |____       (C)2003, Mavy & Bigboss ( mavy@ps2reality.net , 
#						      bigboss@ps2reality.net )
#  ---------------------------------------------------------------------------


all: build-ps2Perf sample

clean:
	$(MAKE) -C ps2Perf clean
	$(MAKE) -C example clean

build-ps2Perf:
	$(MAKE) -C ps2Perf

sample: build-ps2Perf
	$(MAKE) -C example
