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

Book.o: Book.cpp Book.h Utils.o
	$(CC) $(CFLAGS) Book.cpp

Utils.o: Utils.cpp Utils.o
	$(CC) $(CFLAGS) Utils.cpp

clean:
	rm *.o *~ $(TARGET)
