/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 01/28/17
 * File: Book.cpp
 * Description: Definitions of methods of Book Class.
 */

#include "Book.h"
#include <iostream> //STDIN, STDOUT
#include <fstream>  //ifstream

Book::Book() {
  fileName = "fake.txt";
  wordsArrayPtr = 0;
  numOfWords = 0;
}

Book::Book(std::string newFile) {
  fileName = newFile;
  wordsArrayPtr = 0;
  findInitialSize();
  makeWhitespaceIndex();
}

Book::~Book() {
  delete[] wordsArrayPtr;
}

void Book::test() {
  std::cout << "This number of words is: " << numOfWords << std::endl;
}

void Book::findInitialSize() {
  // need two character readers to count whitespace properly
  char previousChar = 'a';
  char currentChar = 'a';

  // open the file
  std::ifstream inputFile;
  inputFile.open(fileName.c_str());

  while (inputFile) {
    previousChar = currentChar;
    currentChar = inputFile.get();
    if((isspace(previousChar)) && !(isspace(currentChar))) {
      numOfWords++;
    }
  }

  inputFile.close();
}

void Book::makeWhitespaceIndex() {
  // allocate memory for the array
  wordsArrayPtr = new std::string[numOfWords];

  // open the file
  std::ifstream inputFile;
  inputFile.open(fileName.c_str());

  for (int i = 0; i < numOfWords; i++) {
    inputFile >> *(wordsArrayPtr + i);
  }

  //close the file
  inputFile.close();
};

void Book::printCurrentArray() {
  for (int i = 0; i < numOfWords; i++) {
    std::cout << *(wordsArrayPtr + i) << std::endl;
  }
}

void Book::removePunctuationFrontBack() {
  for (int i = 0; i < numOfWords; i++) {
    // convert to c string and loop through
    for (int j = 0; j < wordsArrayPtr[i].length(); j++) {
      if (std::ispunct(wordsArrayPtr[i].at(j))) {
	wordsArrayPtr[i].at(j) = '*';
      }
    }
    std::cout << wordsArrayPtr[i].length() << std::endl;
  }
}
