#Matt Calayo mcj5gh Makefile lab6 3/11/28
CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG=-Wall -g
OFILES=hashTable.o timer.o wordPuzzle.o
.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "Hash Tables are Hot and Ready!"

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h


clean:
	-rm -f *.0 *~ a.out
