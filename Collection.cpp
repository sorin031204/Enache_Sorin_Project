//
// Created by Sorin Andrei Enache on 18/05/24.
//

#include "Collection.h"
#include "iostream"

void Collection::readNotes() {
    for (const auto it: Notes)
        std::cout << it.getTitle() << ":" << it.getText() << std::endl;
}

void Collection::addObserver(Observer *o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collection::notifyObservers() {
    for (auto observer: observers)
        observer->Update();
}

Note *Collection::findNoteByTitle(const std::string &title) {
    for (auto &note: Notes) {
        if (note.getTitle() == title) {
            return &note;
        }
    }
    return nullptr;
}

bool Collection::addNote(const Note &note) {
    if (Size < Dimension) {
        Notes.push_back(note);
        Size++;
        notifyObservers();
        return true;
    } else {
        throw std::runtime_error("Collection is full");
    }
}

bool Collection::removeNote(const Note &note) {
    auto it = std::find_if(Notes.begin(), Notes.end(), [&](const Note &n) { return n.getTitle() == note.getTitle(); });
    if (it != Notes.end()) {
        if (!note.isLocked()) {
            Notes.erase(it);
            Size--;
            notifyObservers();
            return true;
        } else {
            throw std::runtime_error("Cannot remove a locked note.");
        }
    } else {
        throw std::runtime_error("Note not found");
    }
}

bool Collection::updateNote(const std::string &title, const std::string &newTitle, const std::string &newText) {
    Note *note = findNoteByTitle(title);
    if (note) {
        if (!note->isLocked()) {
            note->modifyTitle(newTitle);
            note->modifyText(newText);
            notifyObservers();
            return true;
        } else {
            throw std::runtime_error("Cannot update a locked note.");
        }
    } else {
        throw std::runtime_error("Note not found.");
    }
}