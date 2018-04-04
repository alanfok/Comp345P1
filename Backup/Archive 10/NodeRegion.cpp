//
// Created by fok poon kai on 2018-03-09.
//
#include "NodeRegion.h"
#include "ListofPlayer.h"

NodeRegion::NodeRegion() {
    this->region_num=0;
    this->region_population=0;
    this->region_status="";
    this->player_race="";
    this->player_specialpower="";
    this->lost_tride=false;
    this->id_player = 0;

}

NodeRegion::NodeRegion(int region_num, int region_population ,string region_status
        ,string player_race,string player_specialpower,bool losttride, int id_player){
    this->region_num=region_num;
    this->region_population=region_population;
    this->region_status=region_status;
    this->player_race=player_race;
    this->player_specialpower=player_specialpower;
    this->lost_tride=losttride;
    this->id_player=id_player;
};

//get
int NodeRegion::getid_player() {
    return id_player;
}
int NodeRegion::getregion_num() {
    return region_num;
}

int NodeRegion::getregion_population() {
    return region_population;
}

string NodeRegion::getregion_status() {
    return region_status;
}

string NodeRegion::getplayer_race() {
    return player_race;
}

string NodeRegion::getplayer_specialpower() {
    return player_specialpower;
}
bool NodeRegion::getlost_tride() {
    return lost_tride;
}

//set

void NodeRegion::setregion_num(int n) {
    this->region_num=n;
}

void NodeRegion::setregion_population(int n) {
    this->region_population=n;
}

void NodeRegion::setregion_status(string str) {
    this->region_status=str;
}

void NodeRegion::setplayer_race(string str) {
    this->player_race=str;
}


void NodeRegion::setplayer_specialpower(string str) {
    this->player_specialpower=str;
}

void NodeRegion::setlost_tride(bool bn) {
    this->lost_tride=bn;
}

void NodeRegion::setid_player(int id_player) {
    this->id_player=id_player;
}
void NodeRegion::setconquese(listOfPlayer np) {
    this->id_player=np.getidPlayer();
    this->region_population=np.getpopulation();
    this->player_specialpower=np.getspecialPower();
    this->player_race=np.getrace();
}

NodeRegion::~NodeRegion(){};