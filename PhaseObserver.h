//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_PHASEOBSERVER_H
#define COMP345P1_PHASEOBSERVER_H

#include "Observer.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>
#include "ListofPlayer.h"
using namespace std;

class PhaseObserver:public Observer{
public:
//
    PhaseObserver();
    virtual void update(ListofPlayer *lp);

    string phase;
    ListofPlayer *lpp;
//
//

};





#endif //COMP345P1_PHASEOBSERVER_H
