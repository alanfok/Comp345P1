//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_SUBJECT_H
#define COMP345P1_SUBJECT_H

#include "Observer.h"
//#include "PhaseObserver.h"
#include <vector>
#include "ListofPlayer.h"
using namespace std;
/**
 * Interface for the Subject
 */
class Subject {

protected:
    vector <Observer*> observer;
public:
       // class Observer;
       //

       Subject(){};
    ~Subject(){};
    virtual void attach(Observer *observer) ;
    virtual void detach(Observer *observer) ;
    virtual void notify(ListofPlayer *pl);




};

#endif //COMP345P1_SUBJECT_H
