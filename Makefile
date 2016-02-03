#define the compiler to use
CPP = g++

#Compiler and linker flags
CPPFLAGS= -I${GSLINC} -O2 -std=c++11
LDFLAGS= -L${GSLINC}
LDLIBS= -lgsl -lgslcblas

all: ants

ants: antsDriver.o antsUpdate.o antsInit.o antsOutput.o
	${CPP} -o ants antsInit.o antsUpdate.o antsOutput.o antsDriver.o 

antsDriver.o: antsDriver.cc antsDriver.h antsUpdate.h antsInit.h antsOutput.h
	${CPP} ${CPPFLAGS} -c -o antsDriver.o antsDriver.cc

antsUpdate.o: antsUpdate.cc antsUpdate.h antsDriver.h
	${CPP} ${CPPFLAGS} -c -o antsUpdate.o antsUpdate.cc

antsInit.o: antsInit.cc antsInit.h antsDriver.h
	${CPP} ${CPPFLAGS} -c -o antsInit.o antsInit.cc

antsOuput.o: antsOutput.cc antsOutput.h antsDriver.h
	${CPP} ${CPPFLAGS} -c -o antsOutput.o antsOutput.cc

clean:
	rm -f antsDriver.o antsInit.o antsUpdate.o antsOutput.o ants
