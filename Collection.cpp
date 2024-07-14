//
// Created by Sorin Andrei Enache on 18/05/24.
//

#include "Collection.h"
#include "iostream"

void Collection::ReadNotes(){
    for (const auto it : Notes)
        std::cout << it.getTitle() << ":" << it.getText() << std::endl;
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
    }
    NotifyObservers();
}

void Collection::RemoveNote(const Note &note) {
    auto it = std::find_if(Notes.begin(), Notes.end(), [&note](const Note& n) { return n.getTitle() == note.getTitle(); });
    if (it != Notes.end() && !note.StatusNote()) {
        Notes.erase(it);
        Size--;
        NotifyObservers();
    }
}

