/*New term.h file
*/
#ifndef TERM_H
#define TERM_H


#include <string>

class Term {
private:
    std::string term; // actual term itself
    int* docIDPtr;    // array of all docId's containing term
    int docCount;     // number of documents containing term

public:
    Term();
    explicit Term(std::string term);
    void setTerm(std::string term);
    std::string getTerm();
    void setDocIDPtr(int* docIdPtr);
    int* getDocIDPtr();
    void incrementDocCount();
    void addDocID(int ID);
    /*
     * Description:
     *   Appends docId to back of docIdPtr Array.  This function
     *   resizes the array as well.  Will always add to the back!
     */
};

#endif
