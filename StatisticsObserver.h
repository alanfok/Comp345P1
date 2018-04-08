//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_STATISTICSOBSERVER_H
#define COMP345P1_STATISTICSOBSERVER_H
#include "Observer.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>

using namespace std;

class StatisticsObserve:public Observer{
public:
    StatisticsObserve();
    virtual void update( vector<ListofPlayer> *lp_vPtr,int numberOfRegion);



};
#endif //COMP345P1_STATISTICSOBSERVER_H
