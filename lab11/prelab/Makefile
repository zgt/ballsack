#Matt Calayo mjc5h 4/23/18 Makefile

CXX= clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -g
OFILES= topological.o
.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)
	doxygen

topological.o: topological.cpp

clean:
	/bin/rm -f *.o *~
