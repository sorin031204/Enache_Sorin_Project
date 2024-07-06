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

    virtual void NotifyObservers() override;

    virtual void AddObserver(Observer *o) override;

    virtual void RemoveObserver(Observer *o) override;

    int getSize() const{
        return Size;
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