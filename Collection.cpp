//
// Created by Sorin Andrei Enache on 18/05/24.
//

#include "Collection.h"
#include "iostream"


void Collection::AddNote(const Note& note) {
    if (Size < Dimension)
        Notes[Size++] = note;
    else{
        std::cout << "collection is full" << std::endl;
    }
}
