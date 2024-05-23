//
// Created by Sorin Andrei Enache on 21/05/24.
//

#include <iostream>
#include "ImportantCollection.h"

void ImportantCollection::ReadNote(const Note &note) const {
    if (note.StatusNote()){
        std::cout << note.getTitle() << std::endl;
        std::cout << note.getText() << std::endl;
    }

}