bin=task03

CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
src=$(wildcard *.cpp)
obj=$(src:.cpp=.o)

$(bin): $(obj)
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) $(bin)
