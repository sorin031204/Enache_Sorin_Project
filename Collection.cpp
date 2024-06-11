//
// Created by Sorin Andrei Enache on 18/05/24.
//

#include "Collection.h"
#include "iostream"

void Collection::ReadNotes(){
    for (const auto it : Notes)
        std::cout << it.getTitle() << std::endl << it.getText() << std::endl;
}

void Collection::AddObserver(Observer *o) {
    observers.push_back(o);
}

void Collection::RemoveObserver(Observer *o) {
    observers.remove(o);
}

void Collection::NotifyObservers() {
    for (auto observer: observers)
        observer->Update();
}

void Collection::AddNote(const Note &note) {
    if (Size < Dimension) {
        Notes.push_back(note);
        Size++;
        std::cout << "the note " << note.getTitle() << " has been added" << std::endl;
    } else {
        std::cout << "collection is full" << std::endl;
    }
    NotifyObservers();
}

void Collection::RemoveNote(Note &note) {
    for (std::vector<Note>::iterator it = Notes.begin(); it != Notes.end();)
        if (!note.StatusNote()) {
            *it = note;
            it = Notes.erase(it);
        }
    NotifyObservers();
}

