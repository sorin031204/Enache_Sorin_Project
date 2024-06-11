//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include <iostream>

using namespace std;

Note::Note(std::string Title, std::string Text) : Title(Title), Text(Text), Lock(false), Important(false) {}

void Note::LockNote() {
    Lock = true;
}

void Note::UnLockNote() {
    Lock = false;
}

bool Note::StatusNote() const {
    return Lock;
}

bool Note::IsImportant() const {
    return Important;
}

void Note::modifyText(Note &note, std::string NewText) const {
    if (Lock)
        note.Text = NewText;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}

void Note::modifyTitle(Note &note, std::string NewTitle) const {
    if (Lock)
        note.Title = NewTitle;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}