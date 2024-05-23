//
// Created by Sorin Andrei Enache on 21/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_IMPORTANTCOLLECTION_H
#define ENACHE_SORIN_PROJECT_IMPORTANTCOLLECTION_H

#endif //ENACHE_SORIN_PROJECT_IMPORTANTCOLLECTION_H

#include "Collection.h"
#include <iostream>

class ImportantCollection : public Collection {
public:
    explicit ImportantCollection(std::string collectionName, int dimension) : Collection(collectionName, dimension){};

    void ReadNote(const Note& note) const override;


};