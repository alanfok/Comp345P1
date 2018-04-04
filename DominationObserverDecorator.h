//
// Created by fok poon kai on 2018-04-03.
//

#ifndef COMP345P1_DOMINATIONOBSERVERDECORATOR_H
#define COMP345P1_DOMINATIONOBSERVERDECORATOR_H
#include <iostream>
#include <vector>

using namespace std;
#include "gameStatsObserver.h"

class DominationObserverDecorator : gameStatsObserver{
public:
    void regions_lost(vector <int> lostRegions, int nbplayers ) ;
    void update_region_control(vector <int> playercounter,int nbplayers);
    void regions_owned(vector <int> playercounter,int nbplayers, Player player);
    int one;
    int two;
    int three;
    int four;
    int five;

    //virtual void player_cards(int population_number , int nbplayers , vector <listOfPlayer> vplayer);
    // int *numberregionlost [5];
};

#endif //COMP345P1_DOMINATIONOBSERVERDECORATOR_H
