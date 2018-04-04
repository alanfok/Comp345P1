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

class Player :public Tokens{
public:

    Die die;
    Tokens tokens;

    //Interraction interraction;
    bool check=false;
    bool isLostTribe;
    int cost_of_population;

    void picks_race(int race,Player player);
    void conquers(int region, int IdOfplayer, int invade_region,
                  int player_population );
    void withdraw(int idplayer, int region, int nbWithdrawPop);//new added
    int Score();
    void del_pointer();
    void raceToken(int x);

    void token_sort();
    void show_information(vector <listOfPlayer> mp);
    void show_information_of_region();
    int getthrowdie();
    void set_vnodeRegion_Vector(int nbline);
    void pickup(int i, int vicCion, int pop, string sp ,string race, bool decline);// node player
    void setRegionIntoVector();

    vector <listOfPlayer> vplayer;
    vector <NodeRegion> vnodeRegion;
    vector <listOfPlayer> sortbyvplayercoin;
    vector <int> vdecline;  // just holding the player ID
    int special_power_pop_cost_deternment(int playerid,int regoinid);
    void declare_winner();
    void return_puplation_to_occupied_player(int regionid);//when invade the occupied regi
    void conquers_v2(int region, int IdOfplayer , int player_population);
    void withdraw_v2(int region, int Idofplayer , int pop);
    void redeployment(int region, int Idofplayer , int pop);
    void collecttoken(int playid);
    int tempNbIndex;
    void population_costv2(int playid,int regionid);
    void brr();
    void AI_redeployment();
    void test1 ();
    void test2 ();
    void test3 ();
    void test4 ();
    void conquers_v3(int player_population,listOfPlayer *lp, NodeRegion *nr
            , int region ,int invade_region);
    void conquers_v4(listOfPlayer *lp, NodeRegion *nr,int pop);



private:
    void check_region_is_zero_pop(int region);

};
#endif //COMP345P1_PLAYER_H
