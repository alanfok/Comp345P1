//
// Created by fok poon kai on 2018-04-03.
//

#ifndef COMP345P1_GAMESTATSOBSERVER_H
#define COMP345P1_GAMESTATSOBSERVER_H

#include "Player.h"
#include <vector>

class gameStatsObserver {
public:
    virtual void regions_lost(vector <int> lostRegions, int nbplayers )  = 0;
    /*int playerid;
    virtual void update_region_control(vector <int> playercounter,int nbplayer) = 0;
    virtual void region_counter(vector <int> playercounter,int nbplayers, Player player) = 0;
    virtual void get_turn_number(int turn) = 0;*/
    //virtual void
};

#endif //COMP345P1_GAMESTATSOBSERVER_H
