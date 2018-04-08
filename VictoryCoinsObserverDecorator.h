//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_VICTORYCOINSOBSERVERDECORATOR_H
#define COMP345P1_VICTORYCOINSOBSERVERDECORATOR_H
#include "ObserverDecorator.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>
using namespace std;
class VictoryCoinsObserverDecorator: public ObserverDecorator{
public:
    VictoryCoinsObserverDecorator(Observer decoratedObserver) :ObserverDecorator(decoratedObserver) {};
    virtual void Update(ListofPlayer *lp);

};
#endif //COMP345P1_VICTORYCOINSOBSERVERDECORATOR_H
