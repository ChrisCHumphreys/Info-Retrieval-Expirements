/*term.cpp placeholder */

#include <iostream>
#include "Term.h"

Term::Term() {
}

Term::Term(std::string term) {
    this->term = term;
    this->docCount = 0;
}

void Term::setTerm(std::string term) {
    this->term = term;
}

std::string Term::getTerm() {
    return term;
}

void Term::setDocIDPtr(int* docIdPtr) {
    this->docIDPtr = docIDPtr;
}

int* Term::getDocIDPtr() {
    return docIDPtr;
}

void Term::incrementDocCount() {
    docCount++;
    int* tempHolder = new int[docCount];
    // copy all old items into temp array
    for (int i = 0; i < docCount; i++) {
        tempHolder[i] = docIDPtr[i];
    }

    // TODO follow up
    // delete[] docIDPtr;

    docIDPtr = new int[docCount];

    for (int i = 0; i < docCount; i++) {
        docIDPtr[i] = tempHolder[i];
    }

    delete[] tempHolder;
}

void Term::addDocID(int ID) {
    docIDPtr[docCount-1] = ID;
}

