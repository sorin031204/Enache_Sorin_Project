//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include <iostream>

using namespace std;

Note::Note() : Title(Title), Text(Text), Lock(false) {}

bool Note::LockNote(const Note &note) {
    return Lock = true;
}

bool Note::UnLockNote(const Note &note) {
    return Lock = false;
}

bool Note::StatusNote(const Note &note) const {
    return Lock;
}

void Note::modifyText(Note &note, std::string newText) const {
    if (!StatusNote(note))
        note.Text = newText;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}