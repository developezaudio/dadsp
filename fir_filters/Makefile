INCLUDES = -I./
LIBS = -lsndfile
CFLAGS = -std=c++17
PROGS = firtest
CC=g++

all: $(PROGS)
firtest: test.cpp
	$(CC) -o test test.cpp $(INCLUDES) $(LIBS) $(CFLAGS)