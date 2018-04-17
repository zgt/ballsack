#Matt Calayo mjc5gh 4/16/18 Makefile

CXX = clang++
CXXFLAGS= -Wall -g
OFILES= huffmanNode.o huffmandec.o
.SUFFIXES=.o .cpp

make: $(OFILES)
	$(CXX) $(OFILES)


huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h


clean:
	-rm -f *.o *~ a.out
