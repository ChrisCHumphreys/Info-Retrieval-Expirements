/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 02/03/18
 * File: InvertedIndex.h
 * Descriptiong: Attributes and method declarations for 
 *   library class.
 */

#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <string>
#include "Term.h"
#include "Book.h"

class InvertedIndex {
 private:
  int fileCounter;         // number of books in documentList
  Book* documentList;      // array of book objects
  std::string* fileNames;  // array of filenames
  char* dir_name;          // directory where books are stored
  int* DocIds;             // integer id number for docs
  std::string filePath;    // path to folder contating files
  Term* termList;          // array of term objects
  
  void explore(char* dir_name);
  /*
   *  Description:
   *    Reads in the value of 'dir_name', and sets fileNames equal to what they should be.
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   *      Updated values in fileCounter, fileNames.
   */
  
  void createDocuments();  
  /*
   *  Description:
   *    Reads in the value of 'dir_name', navigates to that folder and creates an
   *    arrray of book objects.  One for each file in the folder.  
   *    TODO  add docID value to book objects, let Library set.
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   *      Updated values in fileCounter, documentList, fileNames, and docIds.
   */
  void createIndex();
  /*
   *  Description:
   *    NOT TO BE USED - WILL THROW EXPCEPTION
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   */
 public:
  InvertedIndex();
  /*
   *  Description:
   *    NOT TO BE USED - WILL THROW EXPCEPTION
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   */
  InvertedIndex(std::string filePath);
  /*
   *  Description:
   *    NOT TO BE USED - WILL THROW EXPCEPTION
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   */
  ~InvertedIndex();
  /*
   *  Description:
   *    NOT TO BE USED - WILL THROW EXPCEPTION
   *    
   *  Inputs:
   *    None
   *  
   *  Outputs:
   *    None
   */
};

#endif
