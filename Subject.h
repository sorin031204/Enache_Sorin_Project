//
// Created by Sorin Andrei Enache on 11/06/24.
//

#ifndef ENACHE_SORIN_PROJECT_SUBJECT_H
#define ENACHE_SORIN_PROJECT_SUBJECT_H
#endif //ENACHE_SORIN_PROJECT_SUBJECT_H

class Subject {
public:
    virtual ~Subject() {}

    virtual void AddObserver(Observer *o) = 0;

    virtual void RemoveObserver(Observer *o) = 0;

    virtual void NotifyObservers() = 0;

};