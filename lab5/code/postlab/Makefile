#Matt Calayo mcj5gh Makefile lab5 3/1/28
CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2
DEBUG=-Wall -g
OFILES=AVLTree.o BinarySearchTree.o TreePathTest.o
.SUFFIXES: .o .cpp

pizza: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out
	@echo "Trees are Hot and Ready!"
AVLTree.o: AVLTree.cpp AVLTree.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
TreePathTest.o: TreePathTest.cpp AVLTree.h BinarySearchTree.h

clean:
	-rm -f *.0 *~ a.out
