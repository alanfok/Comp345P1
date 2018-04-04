//
// Created by Claudia Feochari on 2018-04-02.
//

#ifndef SW_VICTORYCOINSOBSERVERDECORATOR_H
#define SW_VICTORYCOINSOBSERVERDECORATOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Player.h"
using namespace std;

class VictoryCoinsObserverDecorator {
public:

    void coins_scored(int nb, Player py);

};

#endif //SW_VICTORYCOINSOBSERVERDECORATOR_H