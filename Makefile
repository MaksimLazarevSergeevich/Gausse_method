PROJECT = gausse

LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
AR = ar
ARFLAGS = rsv

CXXFLAGS = -I. -I/usr/include/eigen3 -Iexternals/lazycsv/include -std=c++17 -Wall -g -fPIC

LDFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDFLAGS) -lgtest -lgtest_main -lpthread

DEPS = $(wildcard *.h)
OBJ = csv_functions.o gausse_metod.o
TEST-OBJ = test-gausse.o

.PHONY: default all test clean cleanall

default: all

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDFLAGS)

$(TESTPROJECT): $(LIBPROJECT) $(TEST-OBJ)
	$(CXX) -o $@ $(TEST-OBJ) $(LDGTESTFLAGS)

test: $(TESTPROJECT)

all: $(PROJECT)

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT) $(LIBPROJECT) $(TESTPROJECT)
