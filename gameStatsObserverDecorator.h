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

class gameStatsObserverDecorator: gameStatsObserver {
public:
    Maps m;
    int playerid;

    void update_region_control(vector <int> playercounter,int nbplayer);
    void region_counter(vector <int> playercounter,int nbplayers, Player player);
    void get_turn_number(int turn);
    ///virtual void regions_lost(vector <int> lostRegions, int nbplayers );
    /*virtual void regions_lost(vector <int> lostRegions, int nbplayers );
    virtual void regions_owned(vector <int> playercounter,int nbplayers, Player player)=0 ;
    virtual void player_cards(int population_number , int nbplayers , vector <listOfPlayer> vplayer)=0;*/

};
#endif //COMP345P1_GAMESTATSOBSERVERDECORATOR_H
