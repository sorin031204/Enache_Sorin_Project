//
// Created by Sorin Andrei Enache on 15/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_NOTE_H
#define ENACHE_SORIN_PROJECT_NOTE_H
#endif //ENACHE_SORIN_PROJECT_NOTE_H
#include "iostream"

using namespace std;

class Note {
public:
    Note(std::string Title , std::string Text);

    bool LockNote(const Note &note);

private:
    string Title;
    string Text;
    bool Lock;
};