SOURCE= makefile
DEF= include/*.hh include/**/*.hh
CLSS= src/*.cpp src/**/*.cpp main.cpp
OBJS= *.o
OUT= main
CFLAGS= -Wall -ggdb

all: compile generate

compile: $(DEF)
	g++ -c $(CLSS) $(CFLAGS)

main: $(DEF)
	g++ -c main.cpp $(CFLAGS)

generate:
	g++ $(OBJS) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
