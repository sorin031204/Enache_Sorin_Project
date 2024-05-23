//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include <iostream>

using namespace std;

Note::Note(std::string Title , std::string Text) : Title(Title), Text(Text), Lock(false) {}

bool Note::LockNote() {
    return Lock = true;
}

bool Note::UnLockNote() {
    return Lock = false;
}

bool Note::StatusNote() const {
    return Lock;
}

void Note::modifyText(Note &note, std::string newText) const {
    if (!StatusNote())
        note.Text = newText;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}