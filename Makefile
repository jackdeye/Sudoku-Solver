appname := sudoku-solver
CXX := g++
CXXFLAGS := -Wall -g

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp" ! -name "testSuite.cpp")
test_srcfiles := $(shell find . -maxdepth 1 -name "*.cpp" ! -name "solver.cpp")

objects  := $(patsubst %.cpp, %.o, $(srcfiles))
test_objects  := $(patsubst %.cpp, %.o, $(test_srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

test: $(test_objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname)-test $(test_objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects) $(test_objects)

dist-clean: clean
	rm -f *~ .depend

include .depend

