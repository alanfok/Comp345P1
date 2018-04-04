//
// Created by fok poon kai on 2018-04-03.
//

#ifndef COMP345P1_GAMESTATSOBSERVERDECORATOR_H
#define COMP345P1_GAMESTATSOBSERVERDECORATOR_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Observer.h"
#include "gameStatsObserver.h"

using namespace std;

class gameStatsObserverDecorator {
public:
    int playerid;
    /*void update_region_control(vector <int> playercounter,int nbplayer);
    void region_counter(vector <int> playercounter,int nbplayers, Player player);*/
    void get_turn_number(int turn);
};
#endif //COMP345P1_GAMESTATSOBSERVERDECORATOR_H
