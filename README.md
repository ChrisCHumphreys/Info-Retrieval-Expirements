# Info-Retrieval-Expirements
Trying to reinvent the wheel of Information Retrieval so I can better understand it.

Warning:
  This code is very much at the beginning stages.  It doesn't do much right now, and what it does is not
  intuitive or done very well.  Hopefully in time this will change.

Description:
  I am attempting to make a very basic search engine in c++ so I can better understand the principles
  of information retrieval.  I am doing this in my spare time so it will probably move slowly.  Eventually,
  given a library of text files, I would like to be able to perform boolean searches for different words
  and be able to be reasonably confident that the results acheived were those desired by the user.
  
TODO:
  In progress -  
  Make a utilities class with a merge sort algorithm.  should accept an usorted array pointer and
  return a sorted array pointer.

  Future -
  Create a Library class that contains the book objects
  make a main that allows a user to specify the library folder and do boolean searches.
  
Usage:
  On linux systems with g++ and make, just go into the root of the project and type `make`.  There will be 
  a new executeable called `tokenizer`.  Just type `./tokenizer` to run.
  
Assumptions:
  This is very much code for testing and playing around.  To have it work on other files you need to go to 
  the code in readIn.cpp and update the constant at the top of the file.  Good Luck!

Note:
  All .txt file for testing should be public domain.  If you notice one is not please let me know so it
  can be removed.
