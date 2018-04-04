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
#include "Observer.h"
#include "Strategy.h"





using namespace std;
class Interraction{
public:
    Player player;
    Veiwer veiwer;
    Maploader maploader;
    Tokens tokens;
    Maps maps;
   // Observer observer;
    AggressivePlayer aggressivePlayer;
    DefensivePlayer  defensePlayer;
    ModeratePlayer moderatePlayer;
    //HumanPlayer humanPlayer;
    RandomPlayer randomPlayer;
    int tempvplayerid;
    int tempvplayerpop;
    int temp_id;


    int input;
    int temp_population=2;//all region need at least 2 to occupied
    string x;
    int input_from;
    int input_to;
    void setplayer(string map,int nbplayer);
    bool nextturn;//for turn2-10
    bool Occupiedcheck2To10;//for turn 2-10
    bool pick_pop_during_Occupied2To10;//for turn 2-10
    bool Redeploymentcheck2TO10;
    int nbOfracetaking;
    int nb_pop;
    int victorycoin;
    int input_select;
    int input_temp_enter_pop;
    bool flag_Occ;//check the Occupied
    bool flag_redeployment;//check the redeployment
    bool first_time_edge;
    bool edge_check;
    int race_coin  [6] ={0,0,0,0,0,0};
    void population_cost(int regionid , int playerid);
    void invade_pack(int input_to, int tempvplayerid, int temp_occ_pp);
    void br();

};






#endif //COMP345P1_INTERRACTION_H
