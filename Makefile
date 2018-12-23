#  _____     ___ ____
#   ____|   |    ____|      PSX2 OpenSource Project
#  |     ___|   |____       (C)2003, Mavy & Bigboss ( mavy@ps2reality.net ,
#                                                     bigboss@ps2reality.net)
#  --------------------------------------------------------------------------


all: 
	$(MAKE) -C ee

install: all
	$(MAKE) -C ee/ps2Perf/ install

clean:
	$(MAKE) -C ee clean

sample:
	$(MAKE) -C ee sample
