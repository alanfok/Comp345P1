//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_PHASEOBSERVER_H
#define COMP345P1_PHASEOBSERVER_H

//#include "Decorator.h"
#include "Player.h"
using namespace std;

//class Player;

class PhaseObserver : public Observer
{
public:
    PhaseObserver();
    virtual void Update(Player*);
    //virtual void Update(int numRegion, Player * p);
};

#endif //COMP345P1_PHASEOBSERVER_H
