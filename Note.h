//
// Created by Sorin Andrei Enache on 15/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_NOTE_H
#define ENACHE_SORIN_PROJECT_NOTE_H

#include "iostream"

#endif  //ENACHE_SORIN_PROJECT_NOTE_H


class Note {
public:
    Note(std::string Title, std::string Text);

    ~Note() {}

    void LockNote();

    void UnLockNote();

    bool StatusNote() const;

    bool IsImportant() const;

    std::string getTitle() const {
        return Title;
    };

    std::string getText() const {
        return Text;
    }

    void modifyText(const std::string &newText);

    void modifyTitle(const std::string &newTitle);


private:
    std::string Title;
    std::string Text;
    bool Lock;
    bool Important;
};