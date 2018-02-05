/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 02/03/18
 * File: InvertedIndex.h
 * Descriptiong: Attributes and method declarations for 
 *   library class.
 */

#include <string>


class InvertedIndex {
 private:
  int fileCounter;
  std::string* fileNames;
  char* dir_name;
  int* DocIds;
  // path to folder contating files
  std::string filePath;
  void createIndex();
  
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
  ~InvertedIndex();
  void explore(char* dir_name);
  void setFilePath(std::string filePath);
  void reCreateIndex(std::string filePath);
  
};
