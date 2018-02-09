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
#include "Term.h"

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
  delete[] termList;
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
    //createIndex();
  }
  createIndex();
}

void InvertedIndex::createIndex() {
  // Create index
  // temporary term object to hold objects during index creation.
  Term tempTerm;
  
  
  // for each document in documentList
  for (int i = 0; i < 1; i++) {
    // for each term in that documents termList
    termList = new Term[documentList[i].getNumOfWords()];
    for (int j = 0; j < (documentList + i)->getNumOfWords(); j++) {
      // create a term object
      tempTerm = Term(*((documentList + i)->getwordsArrayPtr() + j));
      tempTerm.incrementDocCount();
      tempTerm.addDocID(i); 
      *(termList + j) = tempTerm;
      // std::cout << (termList + j)->getTerm() << std::endl;
      //std::cout << "Print a lot" << std::endl;
    }
    Term* oldPtr = termList;
    //std::string* newPtr = documentList[i].wordsArrayPtr;
    int additionalTerms = 0;
   /*
    if (i >= 1) {
      while ((oldPtr->getTerm() != NULL) && (newPtr != NULL)) {
	
      // find out how many more unique entries there are
 
	  if (*oldPtr == *newPtr) {
	    oldPtr++;
	    newPtr++;
	  }
	  else if (*oldPtr < *newPtr) {
	    *oldPtr++;
	    additionalTerms++;
	  }
	  else if (*oldPtr > *newPtr) {
	    *newPtr++;
	    additionalTerms++;
	  }

	  // resize the current array to hold both
	  // refill the old array
	  }
    }
      */
    additionalTerms = 0;
  }

  for (int i = 0; i < documentList[0].getNumOfWords(); i++) {
    std::cout << (termList + i)->getTerm() << std::endl;
  }
  //                    v
  //old  A  C   F   J   
  //                        v
  //new  A  B   F   R   T
}


//Bob 3 8
//run 2 8 10
//cat 1 4
//dog 2 9 12

// term object
//
// term - bob
// array -> docids
