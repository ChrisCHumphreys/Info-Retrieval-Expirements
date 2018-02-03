/* 
 * Name: Chris Humphreys (geochris35@gmail.com)
 * Date: 01/28/17
 * Description: Just a little program I am messing with to help me
 *   in my understanding of information retrieval.  This program
 *   will read a text file into an array.  More to come.
 */

#include <string> 
#include "Book.h"
#include "InvertedIndex.h"

// test files are littleTest.txt and 2000010.txt
const std::string FILE_BEING_READ = "warpeace.txt";
const std::string PATH_TO_TEXT_FILES = "books/";

using namespace std;

int main() {
  //  Book book1(PATH_TO_TEXT_FILES + FILE_BEING_READ);
  InvertedIndex test("cd /home/chris/ResearchProject/myCode/books/");
}
