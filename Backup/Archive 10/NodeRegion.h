//
// Created by fok poon kai on 2018-03-09.
//

#ifndef COMP345P1_NODEREGION_H
#define COMP345P1_NODEREGION_H

#include <iostream>
#include <string>
#include "ListofPlayer.h"


using namespace std;
class NodeRegion{
public :
    int region_num;
    int region_population;
    int id_player;
    string region_status;
    string player_race;
    string player_specialpower;
    bool lost_tride;

    NodeRegion();
    NodeRegion(int region_num, int region_population ,string region_status,
               string player_race,string player_specialpower,bool losttride
                ,int id_player);
    ~NodeRegion();
//get
    int getregion_num();
    int getregion_population();
    string getregion_status();
    string getplayer_race();
    string getplayer_specialpower();
    bool getlost_tride();
    int getid_player();
//set

    void setregion_num(int n);
    void setregion_population(int n);
    void setregion_status(string str);
    void setplayer_race(string str);
    void setplayer_specialpower(string str);
    void setlost_tride(bool bn);
    void setid_player(int id_p);
    void setconquese(listOfPlayer np);
};




#endif //COMP345P1_NODEREGION_H
