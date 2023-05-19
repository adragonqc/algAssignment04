####Zach######

# # Makefile for two programs

# # compiler
# CC = g++

# # compiler flags
# CFLAGS = -std=c++11 -Wall

# # All functions are compiled at once (Others cannot be compiled on their own as they have no main())
# main: Main.cpp
# 	$(CC) $(CFLAGS) flow_network_generator.cpp main.cpp -o main

# # clean main
# clean:
# 	rm -f main

####Ariella##########

CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp flow_network_generator.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = flow

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS)  -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f sfml-app # deprecated
	rm -f *.app
	rm -f *.o
	rm -f *.d
	rm -f -r objects/
	rm -f -r dependencies/