//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_DOMINATIONOBSERVERDECORATOR_H
#define COMP345P1_DOMINATIONOBSERVERDECORATOR_H
//https://gist.github.com/dlivingstone/3006324
#include "ObserverDecorator.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>
using namespace std;
class DominationObserverDecorator: public ObserverDecorator{
public:
    DominationObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver) {};
    virtual void Update(vector<ListofPlayer> *lp_vPtr,int numberOfRegion);




};
#endif //COMP345P1_DOMINATIONOBSERVERDECORATOR_H
