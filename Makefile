# File: Makefile
# Author: Chris Humphreys
# Makefile for readIn.cpp program

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=indexer

#Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

all: $(TARGET)

$(TARGET): readIn.o Book.o InvertedIndex.o 
	$(CC) readIn.o Book.o InvertedIndex.o -o $(TARGET)

readIn.o: readIn.cpp InvertedIndex.h
	$(CC) $(CFLAGS) readIn.cpp

Book.o: Book.cpp Book.h Utils.h
	$(CC) $(CFLAGS) Book.cpp

InvertedIndex.o: InvertedIndex.cpp InvertedIndex.h
	$(CC) $(CFLAGS) InvertedIndex.cpp

clean:
	rm *.o *~ $(TARGET)
