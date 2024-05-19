//
// Created by Sorin Andrei Enache on 18/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_COLLECTION_H
#define ENACHE_SORIN_PROJECT_COLLECTION_H

#endif //ENACHE_SORIN_PROJECT_COLLECTION_H
#include <iostream>
#include "Note.h"

class Collection {
public:

    Collection(std::string collectionName, int dimension) : CollectionName(collectionName), Dimension(dimension),
                                                            Size(0) {
        Notes = new Note[dimension]();
    }

    ~Collection() {
        delete[] Notes;
    }

private:
    std::string CollectionName;
    Note *Notes;
    int Size;
    int Dimension;
};