/*
 * Author: Chris Humphreys
 * Date: 01/31/18
 * Description: Header file for Utilities class.  Contains function declarations.
 * File: Utils.h
 */

#ifndef UTILS_H
#define UTILS_H


#include <string>
#include <iostream>

void BottomUpMerge(std::string* unsorted, int iLeft, int iRight, int iEnd, std::string* workArray);
void CopyArray(std::string* workArray, std::string* unsorted, int arraySize);
int min(int A, int B);



std::string* mergeSort(std::string* unsorted, int arraySize) {
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

   // create temp array to work with
  std::string* workArray = new std::string[arraySize];
  
    // Each 1-element run in unsorted is already "sorted"
    // make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted
    for (int width = 1; width < arraySize; width = 2 * width){
      // Array unsorted is full of runs of length width
      for (int i = 0; i < arraySize; i = i + 2 * width) {
	// Merge two runs: unsorted[i:i+width-1] and unsorted[i+widtth:i+2*width-1] to workArray[]
	// or copy unsorted[i:n-1] to B[] (if (i + width >= arraySize))
	BottomUpMerge(unsorted, i, min(i+width, arraySize), min(i+2*width, arraySize), workArray);
      }
      // Now work array 'workArray' is full of runs of length 2* width.
      // Copy array workArray to Array A for next iteration.
      // A more efficient implementation would swap the roles of A and B.
      CopyArray(workArray, unsorted, arraySize);
    }

    delete[] workArray;
    return unsorted;
}

// Left run is unsorted[iLeft: iRight -1].
// Right run is unsorted[iRight:iEnd-1].
void BottomUpMerge(std::string* unsorted, int iLeft, int iRight, int iEnd, std::string* workArray)
{
  int i = iLeft;
  int j = iRight;
  // While there are elements in the left or right runs...
  for (int k = iLeft; k < iEnd; k++) {
    // If the left run head exists and is <= existing right run head.
    if (i < iRight && (j >= iEnd || unsorted[i] <= unsorted[j])) {
      workArray[k] = unsorted[i];
      i = i + 1;
    } else {
      workArray[k]=unsorted[j];
      j = j + 1;
    }
  }
}

void CopyArray(std::string* workArray, std::string* unsorted, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    unsorted[i] = workArray[i];
  }
}

int min(int A, int B) {
  if (A < B) {
    return A;
  } else {
    return B;
  }
}

#endif
