#Matt Calayo mjc5gh 4/24/18 Makefile

CXX= clang++
CXXFLAGS= -O2
OFILES= traveling.o middleearth.o
.SUFFIXES= .o .cpp

main: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)
	doxygen

middleearth.o: middleearth.cpp middleearth.h
traveling.o: traveling.cpp middleearth.h

clean:
	/bin/rm -f *.o *~
