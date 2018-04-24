#Matt Calayo mjc5gh 4/16/18 Makefile

CXX = clang++
CXXFLAGSENC= -Wall -g 
OFILESENC= huffmanenc.o huffmanNode.o huffmanTree.o heap.o
CXXFLAGSDEC= -Wall -g 
OFILESDEC= huffmanNode.o huffmandec.o 
.SUFFIXES=.o .cpp

all: encode decode

encode:  $(OFILESENC)
	$(CXX) $(CXXFLAGSENC) $(OFILESENC) -o encoder
decode:  $(OFILESDEC)
	$(CXX) $(CXXFLAGSDEC) $(OFILESDEC) -o decoder


heap.o: heap.cpp heap.h huffmanNode.h
huffmandec.o: huffmandec.cpp huffmanNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h huffmanTree.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h heap.h


clean:
	-rm -f *.o *~ a.out
