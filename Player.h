//
// Created by fok poon kai on 2018-02-03.
//

#ifndef COMP345P1_PLAYER_H
#define COMP345P1_PLAYER_H

#include <string>
#include "Tokens.h"
#include "Die.h"
#include "ListofPlayer.h"
#include <vector>
#include <algorithm>


//#include "Interraction.handsObserverDecorator"
using   namespace std;

class Player :public Tokens,public Subject{
public:

    Die die;
    Tokens tokens;

    //Interraction interraction;
    bool check=false;
    bool isLostTribe;
    int cost_of_population;
    int tempPlayerId;
    void picks_race(int race,Player player);
    void conquers(int region, int IdOfplayer, int invade_region,
                  int player_population );
    void withdraw(int idplayer, int region, int nbWithdrawPop);//new added
    int Score();
    void del_pointer();
    void raceToken(int x);

    void token_sort();
    void show_information(vector <ListofPlayer> mp);
    void show_information_of_region();
    int getthrowdie();
    void set_vnodeRegion_Vector(int nbline);
    void pickup(int i, int vicCion, int pop, string sp ,string race, bool decline);// node player
    void setRegionIntoVector();

    vector <ListofPlayer> vplayer;
    vector <NodeRegion> vnodeRegion;
    vector <ListofPlayer> sortbyvplayercoin;
    int special_power_pop_cost_deternment(int playerid,int regoinid);
    void declare_winner();
    void return_puplation_to_occupied_player(int regionid);//when invade the occupied regi

    void redeployment(int region, int Idofplayer , int pop);
    void collecttoken(int playid);
    int tempNbIndex;
    void population_costv2(int playid,int regionid);
    void returnToPreviousPlayer(vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr,int regionid);
    void conquers_v3(int player_population,ListofPlayer *lp, NodeRegion *nr
            , int region ,int invade_region);
    void conquers_v4(ListofPlayer *lp,vector <NodeRegion> *nr_vPtr ,int regionid,int pop);
    void redeploymentVeiw(ListofPlayer *lp,vector <NodeRegion> *nr_vPtr);
    void pickupAfterDecline(ListofPlayer * player,string specialpower,string race, int population);

private:
    void check_region_is_zero_pop(int region);

};
#endif //COMP345P1_PLAYER_H