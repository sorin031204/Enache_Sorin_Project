//
// Created by Sorin Andrei Enache on 30/06/24.
//

#ifndef ENACHE_SORIN_PROJECT_DISPLAY_H
#define ENACHE_SORIN_PROJECT_DISPLAY_H

#include "Collection.h"

#endif //ENACHE_SORIN_PROJECT_DISPLAY_H


class Display : public Observer {

public:
    explicit Display(Collection *collection) : collection(collection) {
        collection->addObserver(this);
    }

    ~Display() {
        collection->removeObserver(this);
    }

    void Update() override {
        std::cout << "Display: una nota è stata rimossa/aggiunta , il numero di note adesso è:" << collection->getSize()
                  << std::endl;
    }

private:
    Collection *collection;
};