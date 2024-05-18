//
// Created by Sorin Andrei Enache on 15/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_NOTE_H
#define ENACHE_SORIN_PROJECT_NOTE_H
#endif  //ENACHE_SORIN_PROJECT_NOTE_H
#include <iostream>

using namespace std;

class Note {
public:
    Note(std::string Title, std::string Text);

    bool LockNote(const Note &note);

    bool UnLockNote(const Note &note);

    bool StatusNote(const Note &note) const;

    std::string getTitle() const {
        return Title;
    };

    std::string getText() const {
        return Text;
    }

    void modifyText(Note &note, std::string) const;


private:
    std::string Title;
    std::string Text;
    bool Lock;
};