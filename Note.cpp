//
// Created by Sorin Andrei Enache on 15/05/24.
//

#include "Note.h"
#include "iostream"

using namespace std;

Note::Note(std::string Title , std::string Text) : Title(Title), Text(Text), Lock(false) {}

bool Note::LockNote(const Note &note) {
    return Lock = true;
};