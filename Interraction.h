//
// Created by fok poon kai on 2018-03-09.
//

#ifndef COMP345P1_INTERRACTION_H
#define COMP345P1_INTERRACTION_H

#include "Player.h"
#include "Tokens.h"
#include "Maploader.h"
#include "Maps.h"
#include <vector>
#include <iostream>
#include "ListofPlayer.h"
#include "Veiwer.h"
#include "PhaseObserver.h"
#include "StatisticsObserver.h"
#include "AggressivePlayer.h"
#include "DefensivePlayer.h"
#include "ModeratePlayer.h"
#include "RandomPlayer.h"
#include "HandsObserverDecorator.h"

using namespace std;
class Interraction{
public:
    Player player;
    Veiwer veiwer;
    Maploader maploader;
    Tokens tokens;
    Maps maps;
    ListofPlayer *lp;
    AggressivePlayer aggressivePlayer;

    DefensivePlayer  defensePlayer;
    ModeratePlayer moderatePlayer;
    RandomPlayer randomPlayer;
    int tempvplayerid;
    int tempvplayerpop;
    HandsObserverDecorator *hod;

    vector <int> playercounter;
    vector <int> lostRegions;

    string tempvrace ;
    string tempsp;
    Player* player_pointer;
    PhaseObserver* po;
    StatisticsObserve* so;
    int turn;
    int input;
    int temp_population=2;//all region need at least 2 to occupied
    string maps_using ;//<~~~change
    int temp_id;
    void setplayer(string map, int nbplayer);
    bool nextturn;//for turn2-10
    bool inputCheck;//for turn 2-10
    int raceSelection;
    int numberOfPopulation ;
    int victorycoin;
    int temp_index;

    bool first_time_edge;
    bool edge_check;
    bool check=false;
    int race_coin  [6] ={0,0,0,0,0,0};

    void br();

};







#endif //COMP345P1_INTERRACTION_H