//
// Created by fok poon kai on 2018-04-02.
//

#ifndef COMP345P1_PHASEOBSERVER_H
#define COMP345P1_PHASEOBSERVER_H
#include "ListofPlayer.h"
#include "Player.h"
#include "Observer.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;


class PhaseObserver : public Observer{
public:
    int playerid;
    void update_conquer(vector <listOfPlayer> phaseObserver);
    void update_region_conquer(vector <listOfPlayer> phaseObserver, string region_status, int nb);
    void update_coin(string coin_status ,int nb) ;
    void race_picked(string race ,string specialpower);
    void population(int nbpopulation);
    void get_player_infomation(int nb, Player py);
};
#endif //COMP345P1_PHASEOBSERVER_H
