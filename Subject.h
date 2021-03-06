//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_SUBJECT_H
#define COMP345P1_SUBJECT_H

#include "Observer.h"
//#include "PhaseObserver.h"
#include <vector>
#include "ListofPlayer.h"
#include <iostream>
using namespace std;
/**
 * Interface for the Subject
 */
class Subject {

protected:
    vector <Observer*> observer;
    vector <Observer*> staticObserver;
public:
       // class Observer;
       //

       Subject(){};
    ~Subject(){};
    virtual void attach(Observer *observer) ;
    virtual void detach() ;
    virtual void notify(ListofPlayer *pl);
    virtual void attachStatic(Observer *observer);
    virtual void notifyStatic(vector<ListofPlayer> *lp_vPtr,int numberOfRegion);


};

#endif //COMP345P1_SUBJECT_H
