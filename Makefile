#define the compiler to use
CPP = g++

#Compiler and linker flags
CPPFLAGS= -O2 -g -std=c++11 -Wall
DEBUG= -g -pg -std=c++11 -Wall
LDFLAGS= -L${GSLINC}

all: original ants 

#Modularized code
ants: antsDriver.o antsUpdate.o antsInit.o antsOutput.o ticktock.o
	${CPP} $(CPPFLAGS) -o ants antsInit.o antsUpdate.o antsOutput.o antsDriver.o ticktock.o

antsDriver.o: antsDriver.cc antsDriver.h antsUpdate.h antsInit.h antsOutput.h
	${CPP} $(CPPFLAGS) -c -o antsDriver.o antsDriver.cc

antsUpdate.o: antsUpdate.cc antsUpdate.h antsDriver.h
	${CPP} $(CPPFLAGS) -c -o antsUpdate.o antsUpdate.cc

antsInit.o: antsInit.cc antsInit.h antsDriver.h
	${CPP} $(CPPFLAGS) -c -o antsInit.o antsInit.cc

antsOutput.o: antsOutput.cc antsOutput.h antsDriver.h
	${CPP} $(CPPFLAGS) -c -o antsOutput.o antsOutput.cc

#Original code
original: antsOriginal.o ticktock.o
	${CPP} ${CPPFLAGS} -o  antsOriginal antsOriginal.o ticktock.o

antsOriginal.o: ants.cc
	${CPP} ${CPPFLAGS} -o antsOriginal.o -c ants.cc

#Profiling compilation
debug: gants goriginal

gants: gantsDriver.o gantsUpdate.o gantsInit.o gantsOutput.o ticktock.o
	${CPP} $(DEBUG) -o antsDebug antsInit.o antsUpdate.o antsOutput.o antsDriver.o ticktock.o

gantsDriver.o: antsDriver.cc antsDriver.h antsUpdate.h antsInit.h antsOutput.h
	${CPP} $(DEBUG) -c -o antsDriver.o antsDriver.cc

gantsUpdate.o: antsUpdate.cc antsUpdate.h antsDriver.h
	${CPP} $(DEBUG) -c -o antsUpdate.o antsUpdate.cc

gantsInit.o: antsInit.cc antsInit.h antsDriver.h
	${CPP} $(DEBUG) -c -o antsInit.o antsInit.cc

gantsOutput.o: antsOutput.cc antsOutput.h antsDriver.h
	${CPP} $(DEBUG) -c -o antsOutput.o antsOutput.cc

goriginal: gantsOriginal.o ticktock.o
	${CPP} ${DEBUG} -o antsOriginalDebug antsOriginal.o ticktock.o

gantsOriginal.o: ants.cc
	${CPP} ${DEBUG} -o antsOriginal.o -c ants.cc

#Other
test: BoostTestingUnit.cc antsUpdate.o
	${CPP} -o test BoostTestingUnit.cc antsUpdate.o

ticktock.o: ticktock.cc ticktock.h
	${CPP} $(CPPFLAGS) -o ticktock.o -c ticktock.cc

clean:
	rm -f *.o antsOriginal ants test gmon.out antsOriginalDebug antsDebug
