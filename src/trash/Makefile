CXX= g++
CXX_FLAGS= -g -Wall


SOURCES= $(wildcard *.cpp)
OBJS= $(patsubst %.cpp, %.o, $(SOURCES))
DEP_FILES=$(patsubst %.cpp, %_deps.mk, $(SOURCES))


all: main

include deps.mk

main: $(OBJS)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

%_deps.mk: %.cpp
	$(CXX) -MM -MF $@ $<

deps.mk: $(DEP_FILES)
	rm -f deps.mk
	cat $(DEP_FILES) > deps.mk

clean: 
