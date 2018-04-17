#Matt Calayo mjc5gh 4/16/18 Makefile

CXX = clang++
CXXFLAGS= -Wall -g
OFILES= huffmanNode.o huffmanenc.o huffmanTree.o heap.o
.SUFFIXES=.o .cpp

make: $(OFILES)
	$(CXX) $(OFILES)

heap.o: heap.cpp heap.h huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h huffmanTree.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h heap.h

clean:
	-rm -f *.o *~ a.out
