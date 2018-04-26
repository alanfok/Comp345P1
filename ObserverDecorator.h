//
// Created by fok poon kai on 2018-04-07.
//
//https://gist.github.com/dlivingstone/3006324
#ifndef COMP345P1_OBSERVERDECORATOR_H
#define COMP345P1_OBSERVERDECORATOR_H
#include "Observer.h"
using namespace std;

class ObserverDecorator : public Observer
{
protected:
    Observer DecoratorObserver;
public:

    ObserverDecorator(Observer obs) {
        this->DecoratorObserver = obs;
    }
    virtual void Update(ListofPlayer *pl) {};
    virtual void Update(vector<ListofPlayer> *lp_vPtr,int numberOfRegion) {};
};
#endif //COMP345P1_OBSERVERDECORATOR_H

