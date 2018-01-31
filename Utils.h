/*
 * Author: Chris Humphreys
 * Date: 01/31/18
 * Description: Header file for Utilities class.  Contains function declarations.
 * File: Utils.h
 */

#include <string>


class TokenizerUtilities {
  /*
   * Description:
   *   TokenizerUtilities is just a collection of functions that could
   *   be needed by the the book or library classes.
   */
  
 public:
  std::string*  mergeSort(std::string* unsorted);
  /*
   * Description:
   *   Sorts an array of strings into alphabetical order, using a
   *   merge sort algorithm.
   *
   * Inputs:
   *   string*:
   *     A pointer to a string array of unsorted values
   *  
   * Outputs:
   *   string*;
   *     Returns a pointer to a sorted list.
   */
};
