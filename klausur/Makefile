CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -Werror -pedantic
LDFLAGS=

SRCS=$(wildcard *.cpp)
PRGS=$(patsubst %.cpp,%,$(SRCS))
SUFX=""
BINS=$(patsubst %,%$(SUFX),$(PRGS))
OBJS=$(patsubst %,%.o,$(PRGS))

all: $(BINS)

.SECONDEXPANSION:
OBJ=$(patsubst %$(SUFX),%.o,$@)
BIN=$(patsubst %$(SUFX),%,$@)

%$(SUFX): $(OBJS)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(BIN)

clean:
	$(RM) $(BINS)

rebuild: clean all
