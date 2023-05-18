# Makefile for two programs

# compiler
CC = g++

# compiler flags
CFLAGS = -std=c++11 -Wall

# All functions are compiled at once (Others cannot be compiled on their own as they have no main())
main: Main.cpp
	$(CC) $(CFLAGS) flow_network_generator.cpp Main.cpp -o main

# clean main
clean:
	rm -f main