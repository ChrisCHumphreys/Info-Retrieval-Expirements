/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 02/03/18
 * File: InvertedIndex.cpp
 * Description: Implemention file for library class
 */

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include "Book.h"
#include "InvertedIndex.h"

InvertedIndex::InvertedIndex() {
  // TODO - throw exception
}

InvertedIndex::InvertedIndex(std::string filePath) {
  fileNames = 0;
  fileCounter = 0;
  explore((char*)filePath.c_str());
  // create new array for filenames
  // create a new array for books
  fileNames = new std::string[fileCounter];
  documentList = new Book[fileCounter]; 
  fileCounter = 0;
  explore((char*)filePath.c_str());
  createDocuments();
  
  (documentList+4)->printCurrentArray();
  // leaving in for testing for now.
  //std::cout << "Total # of files = " << fileCounter << std::endl;
  //for (int i = 0; i < fileCounter; i++) {
  //  std::cout << *(fileNames + i) << std::endl;
  //}
}

InvertedIndex::~InvertedIndex() {
  delete[] fileNames;
  delete[] documentList;
}

void InvertedIndex::explore(char* dir_name) {

  DIR* dir; // pointer to open dir
  struct dirent *entry; //stuff in directory
  struct stat info;
  
  dir = opendir(dir_name);
  if (!dir) {
    std::cout << "Directory was not found!" << std::endl;
    return;
  }

  while((entry = readdir(dir)) != NULL) {
    if (entry->d_name[0] != '.') {
      if (fileNames != 0) {
	*(fileNames + fileCounter) = entry->d_name;
      }
      //std::string path = std::string(dir_name) + "/" + std::string(entry->d_name);
      //std::cout << "Entry = " << path << std::endl;
      //stat(path.c_str(), &info);
      fileCounter++;
      //if (S_ISDIR(info.st_mode)){
      //explore((char*)path.c_str());
      //}
    }
  }

  closedir(dir);

}

void InvertedIndex::createDocuments() {
  for (int i = 0; i < fileCounter; i++) {
    *(documentList + i) = Book("books/" + *(fileNames + i)); 
  }
}

  // std::cin >> "/users/chris/Documents/books/" >> std::endl;

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

