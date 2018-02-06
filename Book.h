/*
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 01/28/17
 * File: Book.h
 * Description: Header for Book Class.
 */
#include <string> 

class Book {
/* 
 * Description:  The book class represents one book of the collection
 *   being indexed.  The initial storage will be simply an array of 
 *   terms that were seperated by whitespace in the original.  There will
 *   be methods to strip them of punctuation, and to stem them.
 */

private:
  // Name of the file on disk
  std::string fileName;
  std::string* wordsArrayPtr;
  int numOfWords;
  int docID;

  void findInitialSize();
  /*
   * Description:
   *   Does a run through the file to determine the number of 'words'.  Assigns
   *   this value to Book.numOfWords.  This is very initial.  It only counts
  *   based on whitespace with no filtering whatsoever.
   *   
   * Inputs:
   *   None
   *
   * Outputs:
   *   None - Sets value of 'numOfWords'
   */

  void makeWhitespaceIndex();
  /* 
   * Description:
   *   Loads all words (seperated by whitespace only) into an array pointed to by
   *   'wordsArray'.  This will contain both duplicates and punctuation.
   * 
   *   None
   * 
   * Outputs:
   *   None - Creates a dynamic array pointed to by 'wordsArray'.
   */

  void removeEmpty();
  /*
   * Description:
   *   Removes all empty spots from array and updates Book attributes.
   *
   * Inputs:
   *   None
   *
   * Outputs:
   *   None - updates 'wordsArrayPtr', and 'numOfWords' attributes
   *
   */

  void cleanWords();
  /*
   * Description:
   *   Goes through the document and updates array to remove all punctuation
   *   and numeric digits from words.
   *
   * Inputs:
   *   None:
   *     Works on its own array of words and updates to remove the whitespace.
   *
   * Outputs:
   *   None:
   */
  
  void alphabetizeWords();
  /*
   * Description:
   *   Loops through the books wordsArray and updates the order of the words
   *   to put in alphabetical order.
   *
   * Inputs:
   *   None - works on wordsArrayPtr
   *
   * Outputs:
   *   None - after completion all words in wordsArrayPtr are in order
   */

  void removeDuplicates();
  /*
   * Description:
   *   Removes all duplicate entries from wordsArrayPtr
   *
   * Inputs:
   *   None
   *
   * Outputs:
   *   None - udpates Book attributes
   */
  
public:
  Book();
  /* 
   * Description: 
   *   Default Book constructor.  Creates an empty book object
   *   with no data. Right now being used for testing DO NOT USE!
   */
  
  Book(std::string fileName);
  /*
   * Description: 
   *   Parameterized Book Constructor.  When created reads into 
   *   this.word all the words in the file specified by 'filename'.  Also
   *   creates a whitespace seperated index of terms.
   * 
   * Inputs:
   *  string fileName
   *    A string representing the filename of a text file.  Must be a
   *    text '.txt' file at this time.
   */
  
  ~Book();
  /*
   * Description:
   *   Destructor, frees up wordsArrayPtr.
   */

  void printCurrentArray();
  /*
   * Description:
   *   Prints to the consolse the contents of 'wordsArray' with each
   *   element getting one line.  Mainly for testing.
   *
   * Inputs:
   *   None - Prints to the console
   *
   * Outpus:
   *   None
   */

  void setDocID(int id);
  /*
   * Description:
   *   Simple setter for DocID which will be used by indexer.
   *
   * Inputs:
   *   Int id - an integer representing the document ID number.
   *
   * Outputs;
   *   None:
   */

  int getDocID();
  /*
   * Description:
   *   Simple getter for DocID which will be used by indexer.
   *
   * Inputs:
   *   None:
   *
   * Outputs;
   *   int - an integer representing a docID.
   */
};
