//
// Created by fok poon kai on 2018-02-03.
//

#ifndef COMP345P1_TOKENS_H
#define COMP345P1_TOKENS_H

#include <iostream>
//#include "Maps.handsObserverDecorator"
//#include "Player.handsObserverDecorator"
#include "Maploader.h"
#include <vector>
#include <algorithm>

using namespace std;

class Tokens  {
public:
    int region;
    Maps maps;
    Maploader maploader;
    int temp_of_shift;
    int race_population=0;
    //bool edgechecking;

    vector <string> racess  = {"Amazons","Dwarves","Elves","Ghouls","Ratmen","Skeletons",
                               "Sorecerers","Tritons","Giants","Halfings","Human","Orcs",
                               "Trolls","Wizards"} ;


    vector <string> special_power={"Alchemist","Berserk","Bivouacking","Commando","Diplomat",
                                   "Dragon_Master","Flying","Forest","Fortified","Heroic",
                                   "Hill","Merchant","Mounted","Pillaging","Seafaring"
            ,"Spirit","Stout","Swamp","Underworld","Wealthy" };

    bool edgeentry=false;



    void invade(int idPlayer,int region,int invadeOfRegion);//need
    void point_del();
    void prints();
    vector <string> vrace;
    vector <string> vspecialpower;

    void enter_race_sp_to_vector();
    void shift(int nb_of_race);
    string getvrace(int nb_of_race);
    string getvspecialpower(int nb_of_race);
    void vrace_vspecialpower_print();
    int race_population_determind(string race,string specialpower);
    int getRace_population();
    void setRace_population(int number);


    bool edgecheck(int from , int to);
    void invade_v2(int pyid, int regionid);

};


#endif //COMP345P1_TOKENS