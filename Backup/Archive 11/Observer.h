//
// Created by fok poon kai on 2018-04-01.
//




#ifndef COMP345P1_OBSERVER_H
#define COMP345P1_OBSERVER_H
#include "ListofPlayer.h"
#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;


class Observer {
public:
    vector <listOfPlayer> getPlayerList();
    void attach(listOfPlayer ls);
    void update_coin();
    void update_conquer();
    //void update(vector <listOfPlayer> phaseObserver);
    void update(vector <listOfPlayer> phaseObserver,vector <int> playercounter,
                int nbplayers,string race, string specialpower, int nbpopulation
            ,int nb,Player py,int turn,string coin_status,string region_status,
                vector <int> lostRegions);

    void detach(listOfPlayer ls);
    vector <listOfPlayer> phaseObserver;

};




#endif //COMP345P1_OBSERVER_H
