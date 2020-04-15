# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: UtPodDriver.o UtPod.o Song.o
	g++ -o test  UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp

