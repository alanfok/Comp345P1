//
// Created by fok poon kai on 2018-04-03.
//

#ifndef COMP345P1_HANDSOBSERVERDECORATOR_H
#define COMP345P1_HANDSOBSERVERDECORATOR_H
#include <iostream>
#include <fstream>
#include <vector>
#include "ListofPlayer.h"
using namespace std;

class HandsObserverDecorator {
public:
    void player_cards(int population_number , int nbplayers , vector <listOfPlayer> vplayer);

};
#endif //COMP345P1_HANDSOBSERVERDECORATOR_H