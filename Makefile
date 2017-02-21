CC = g++
CC_FLAGS = -g -O3 -O2 -std=c++14 -Wall -Bstatic -lboost_program_options -lboost_system -lboost_filesystem -lboost_regex

all: TransCopyConfiguration.o
	$(CC) TransCopyConfiguration.o -o TransCopy

TransCopyConfiguration.o:  TransCopyConfiguration.cpp TransCopyConfiguration.h Configuration.h
	$(CC)  -c TransCopyConfiguration.cpp  $(CC_FLAGS)

clean: 
	rm *.o