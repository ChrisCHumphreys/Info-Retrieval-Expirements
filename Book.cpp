/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 01/28/17
 * File: Book.cpp
 * Description: Definitions of methods of Book Class.
 */

#include "Book.h"   // header file
#include "Utils.h"  
#include <iostream> //STDIN, STDOUT
#include <fstream>  //ifstream
#include <cstdlib>  //tolower

Book::Book() {
  fileName = "fake.txt";
  wordsArrayPtr = 0;
  numOfWords = 0;
  // TODO throw exception - communicate to user.
}

Book::Book(std::string newFile) {
  fileName = newFile;
  wordsArrayPtr = 0;
  findInitialSize();
  makeWhitespaceIndex();
  cleanWords();
  alphabetizeWords();
  removeDuplicates();
  // DO NOT PRINT LATER
  printCurrentArray();
}

Book::~Book() {
  wordsArrayPtr = 0;
  delete[] wordsArrayPtr;
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

void Book::cleanWords() {
  // loop through the array and check all words
  for (int i = 0; i < numOfWords; i++) {
     for (int j = 0; j < wordsArrayPtr[i].size(); j++) {
       if (std::ispunct(wordsArrayPtr[i].at(j)) ||
	   (wordsArrayPtr[i].at(j) == '-') ||
	   (wordsArrayPtr[i].at(j) == '"') ||
	   (isdigit(wordsArrayPtr[i].at(j)))) {
	 // just use the built in erase function.
	 wordsArrayPtr[i].erase(j, 1);
	 // bump back j by 1 to account for changed array size
	 j--;
       }
    }
  }
  removeEmpty();

  // convert to lowercase
  for (int i = 0; i < numOfWords; i++) {
    for (int j = 0; j < wordsArrayPtr[i].size(); j++) {
      wordsArrayPtr[i][j] = std::tolower(wordsArrayPtr[i][j]);
    }
  }
}

void Book::removeEmpty() {
  // make a new temp pointer and initialize to wordsArrayPtr
  std::string* tempWordPtr = 0;
  tempWordPtr = wordsArrayPtr;
  
  // reset numOfWords to 0
  int oldWordCount = numOfWords;
  numOfWords = 0;

  // temp counter variable
  int counter = 0;
  
  // get new array size
  for (int i = 0; i < oldWordCount; i++) {
    if (wordsArrayPtr[i].length() != 0) {
      numOfWords++;
    }
  }

  // delete old array and create new one.
  // delete[] wordsArrayPtr;
  wordsArrayPtr = new std::string[numOfWords];

  // read in all words except blank ones
  for (int i = 0; i < oldWordCount; i++) {
    if (tempWordPtr[i].length() != 0) {
      wordsArrayPtr[counter] = tempWordPtr[i];
      counter++;
    }
  }

  delete[] tempWordPtr;
  tempWordPtr = 0;
}


void Book::alphabetizeWords() {
  // just run through merge sort algorithm
  wordsArrayPtr = mergeSort(wordsArrayPtr, numOfWords);
}

void Book::removeDuplicates() {
  // This will only work for a pre-sorted array, duplicates must be next
  // to each other in order to be removed.  Only looks one spot ahead.
  std::string* tempWordPtr = new std::string[numOfWords];
  int tempCounter = 0;

  // copy 1 of each term (no doubles) to temp array
  for (int i = 0; i < numOfWords; i++) {
    if (wordsArrayPtr[i] != wordsArrayPtr[i+1]) {
      tempWordPtr[tempCounter] = wordsArrayPtr[i];
      tempCounter++;
    }
  }

  delete[] wordsArrayPtr;
  wordsArrayPtr = new std::string[tempCounter];
  numOfWords = tempCounter;

  // copy everything back to original array
  for (int i = 0; i < tempCounter; i++) {
    wordsArrayPtr[i] = tempWordPtr[i];
  }

  // delete temp array
  delete[] tempWordPtr;
}
