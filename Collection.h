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

    void NotifyObservers() override;

    void AddObserver(Observer *o) override;

    void RemoveObserver(Observer *o) override;

    int getSize() const{
        return Size;
    }

    int getDimesion() const{
        return Dimension;
    }

    virtual void ReadNotes();

    void AddNote(const Note &note);

    void RemoveNote(const Note &note);

private:
    std::string CollectionName;
    std::vector<Note> Notes;
    int Size;
    int Dimension;
    std::list<Observer *> observers;
};