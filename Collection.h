//
// Created by Sorin Andrei Enache on 18/05/24.
//

#ifndef ENACHE_SORIN_PROJECT_COLLECTION_H
#define ENACHE_SORIN_PROJECT_COLLECTION_H

#include <iostream>
#include "Note.h"
#include "vector"
#include "Observer.h"
#include "list"
#include "Subject.h"

#endif //ENACHE_SORIN_PROJECT_COLLECTION_H

class Collection : public Subject {
public:

    Collection(std::string collectionName, int dimension) : Dimension(dimension), CollectionName(collectionName),
                                                            Size(0) {
        Notes.reserve(Dimension);
    }

    void notifyObservers() override;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    int getSize() const {
        return Size;
    }

    int getDimesion() const {
        return Dimension;
    }

    virtual void readNotes();

    Note* findNoteByTitle(const std::string& title);

    bool addNote(const Note &note);

    bool removeNote(const Note &note);

    bool updateNote(const std::string& searchTitle, const std::string& newTitle, const std::string& newText);

private:
    std::string CollectionName;
    std::vector<Note> Notes;
    int Size;
    int Dimension;
    std::list<Observer *> observers;
};