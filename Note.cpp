//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include <iostream>

using namespace std;

Note::Note(std::string Title, std::string Text) : Title(Title), Text(Text), Lock(false) , Important(false) {}

void Note::LockNote() {
     Lock = true;
}

void Note::UnLockNote() {
     Lock = false;
}

bool Note::StatusNote() const {
    return Lock;
}

void Note::modifyText(Note &note, std::string NewText) const {
    if (!StatusNote())
        note.Text = NewText;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}

void Note::modifyTitle(Note &note, std::string NewTitle) const {
    if (!StatusNote())
        note.Title = NewTitle;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}