/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 02/03/18
 * File: InvertedIndex.cpp
 * Description: Implemention file for library class
 */

#include <iostream>
#include <fstream>
//#include <stdafx.h>
#include <dirent.h>
#include <sys/types.h>
#include "Book.h"
#include "InvertedIndex.h"

InvertedIndex::InvertedIndex() {
  // TODO - throw exception
};

InvertedIndex::InvertedIndex(std::string filePath) {

  dirent* de;
  DIR* dp;
  int tempCounter = 0;
  
  dp = opendir(filePath.c_str());

  while (dp) {
    std::cout << dp << std::endl;
    tempCounter++;
  }

  std::cout << tempCounter << std::endl;

  closedir(dp);
  // std::cin >> "/users/chris/Documents/books/" >> std::endl;
}
  // TODO file path attribute
  // Book id array - parrallel
  // book filenames - parallel


  // REad in all files from path
  //   create a book object for each file
  //   Assign doc id to each file


  // Create index
  // create 2d array
  //   arrar[i] term
  //   array[i][j] doc id's

  // save index to disk as index.txt

InvertedIndex::~InvertedIndex() {
  // do something someday
}
