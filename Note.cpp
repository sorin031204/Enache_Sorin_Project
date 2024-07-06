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

void Note::modifyText(const std::string &newText) {
    if (!Lock)
        Text = newText;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}

void Note::modifyTitle(const std::string &newTitle) {
    if (!Lock)
        Title = newTitle;
    else {
        std::cout << "Cannot modify a locked note." << std::endl;
    }
}