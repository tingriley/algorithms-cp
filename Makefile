CXX=g++
CFLAGS=-Wall
LIBS=-lm

all: KMP.o Z.o BIT.o Prime.o Bridge.o
	$(CXX) -o KMP KMP.o $(LIBS)
	$(CXX) -o Z Z.o $(LIBS)
	$(CXX) -o BIT BIT.o $(LIBS)
	$(CXX) -o Prime Prime.o $(LIBS)
	$(CXX) -o Bridge Bridge.o $(LIBS)
	rm -f *.o

kmp: KMP.o
	$(CXX) -o KMP KMP.o $(LIBS)
	rm -f *.o

zalgo: Z.o
	$(CXX) -o Z Z.o $(LIBS)
	rm -f *.o

BIT: BIT.o
	$(CXX) -o BIT BIT.o $(LIBS)
	rm -f *.o

Prime: Prime.o
	$(CXX) -o Prime Prime.o $(LIBS)
	rm -f *.o

Bridge: Bridge.o
	$(CXX) -o Bridge Bridge.o $(LIBS)
	rm -f *.o


.PHONY: clean

clean:
	rm -f *.o
	rm -f KMP Z BIT Prime Bridge
