# File: Makefile
# Author: Chris Humphreys
# Makefile for readIn.cpp program

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=tokenizer

#Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

all: $(TARGET)

$(TARGET): readIn.o Book.o
	$(CC) readIn.o Book.o -o $(TARGET)

readIn.o: readIn.cpp Book.h
	$(CC) $(CFLAGS) readIn.cpp

Book.o: Book.cpp Book.h
	$(CC) $(CFLAGS) Book.cpp

clean:
	rm *.o *~ $(TARGET)
