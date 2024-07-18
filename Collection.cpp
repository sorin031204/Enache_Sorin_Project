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

void Collection::addNote(const Note &note) {
    if (Size < Dimension) {
        Notes.push_back(note);
        Size++;
    }
    notifyObservers();
}

void Collection::removeNote(const Note &note) {
    auto it = std::find_if(Notes.begin(), Notes.end(),
                           [&note](const Note &n) { return n.getTitle() == note.getTitle(); });
    if (it != Notes.end() && !note.isLocked()) {
        Notes.erase(it);
        Size--;
        notifyObservers();
    }
}

void Collection::updateNote(const std::string& searchTitle, const std::string& newTitle, const std::string& newText) {
    auto it = std::find_if(Notes.begin(), Notes.end(), [&searchTitle](const Note& n) { return n.getTitle() == searchTitle; });
    if (it != Notes.end()) {
        if (!it->isLocked()) {
            it->modifyTitle(newTitle);
            it->modifyText(newText);
            std::cout << "The note with title " << searchTitle << " has been updated." << std::endl;
        } else {
            std::cout << "Cannot update a locked note." << std::endl;
        }
    } else {
        std::cout << "Note with title " << searchTitle << " not found." << std::endl;
    }
    notifyObservers();
}

