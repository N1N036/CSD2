CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= instrument.o guitar.o piano.o bass.o main.o

main: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
	
clean:
	rm -f main *.o
