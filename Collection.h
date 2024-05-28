//
// Created by Sorin Andrei Enache on 18/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_COLLECTION_H
#define ENACHE_SORIN_PROJECT_COLLECTION_H

#endif //ENACHE_SORIN_PROJECT_COLLECTION_H
#include <iostream>
#include "Note.h"
#include "vector"
class Collection {
public:

    Collection(std::string collectionName, int dimension) : Dimension(dimension), CollectionName(collectionName),
                                                            Size(0) {
        Notes.reserve(Dimension);

    }

    virtual void ReadNote(const Note &note) const;

    void AddNote(const Note &note);

private:
    std::string CollectionName;
    std::vector<Note> Notes;
    int Size;
    int Dimension;
};