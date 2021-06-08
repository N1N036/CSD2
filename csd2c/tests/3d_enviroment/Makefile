CXX = g++

SOURCE=  3D_Demo.o

example: $(SOURCE)
	$(CXX) -o $@ $(CXXFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f example *.o