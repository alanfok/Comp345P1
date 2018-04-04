//
// Created by fok poon kai on 2018-04-02.
//

#ifndef COMP345P1_GAMESTATSOBSERVER_H
#define COMP345P1_GAMESTATSOBSERVER_H
#include <iostream>
#include <vector>
#include "Player.h"
#include "Observer.h"
using namespace std;

class gameStatsObserver : public Observer {
public:

    int playerid;
    void update_region_control(vector <int> playercounter,int nbplayer);
    void region_counter(vector <int> playercounter,int nbplayers, Player player);
};
#endif //COMP345P1_GAMESTATSOBSERVER_H
