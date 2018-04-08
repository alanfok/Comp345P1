//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_HANDSOBSERVERDECORATOR_H
#define COMP345P1_HANDSOBSERVERDECORATOR_H
//https://gist.github.com/dlivingstone/3006324
#include "ObserverDecorator.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>
using namespace std;
class HandsObserverDecorator: public ObserverDecorator{
public:
    HandsObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver) {};
    virtual void Update(ListofPlayer *lp);




};
#endif //COMP345P1_HANDSOBSERVERDECORATOR_H
