//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include <iostream>

using namespace std;

Note::Note(std::string Title, std::string Text) : Title(Title), Text(Text), Lock(false), Important(false) {}

void Note::lockNote() {
    Lock = true;
}

void Note::unlockNote() {
    Lock = false;
}

bool Note::isLocked() const {
    return Lock;
}

bool Note::isImportant() const {
    return Important;
}

void Note::modifyText(const std::string& newText) {
    if (!Lock) {
        Text = newText;
    } else {
        throw std::runtime_error("Cannot modify a locked note.");
    }
}

void Note::modifyTitle(const std::string& newTitle) {
    if (!Lock) {
        Title = newTitle;
    } else {
        throw std::runtime_error("Cannot modify a locked note.");
    }
}