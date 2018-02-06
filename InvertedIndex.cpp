/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 02/03/18
 * File: InvertedIndex.cpp
 * Description: Implemention file for library class
 */

#include <iostream> // cout, cin
#include <fstream>  // ofstream
#include <string>   // string
#include <dirent.h>
#include <sys/stat.h>
#include "Book.h"
#include "InvertedIndex.h"

InvertedIndex::InvertedIndex() {
  // TODO - throw exception
}

InvertedIndex::InvertedIndex(std::string filePath) {
  // set attributes
  fileNames = 0; // pointer to filenam array
  fileCounter = 0; // number of file in dir 'filePath'
  explore((char*)filePath.c_str()); // first run updates filecounter to correct value
  fileNames = new std::string[fileCounter];   // create new array for filenames
  documentList = new Book[fileCounter];    // create a new array for books
  fileCounter = 0; // have to reset to 0 or next run will double it
  explore((char*)filePath.c_str()); // second run creates filename array
  createDocuments(); // create book objects
}

InvertedIndex::~InvertedIndex() {
  // clean up old files
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
      // old output for testing wether stream was working, keeping jic
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
    (documentList + i)->setDocID(i);
    // Leaving in - Looks Cool
    std::cout << "This is the doc id: " << (documentList + i)->getDocID() << std::endl;
    std::cout << "This is the doc filename: " << *(fileNames + i) << std::endl;
  }
}

void InvertedIndex::createIndex() {
  // Create index

  // documentList

  // create an object for each word in doc1
  // create an object for 
  // for all additional documents
  //    count number of additional items
  //    make new array of size oldArray + new Items
  //    fill new array with old terms + new terms in order
  //
  // for all documents
  //    check if term is in termlist
  //    if so add docId to term
  //
  // save index to disk as index.txt

}


//Bob 3 8
//run 2 8 10
//cat 1 4
//dog 2 9 12

// term object
//
// term - bob
// array -> docids
