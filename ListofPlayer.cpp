//
// Created by fok poon kai on 2018-03-09.
//
#include "ListofPlayer.h"

ListofPlayer::ListofPlayer()
{
    idPlayer = 0;
    victoryCoins = 0;
    population =0 ;
    specialPower = "";
    race = "";
    decline=false;
    decline_lock=0;
    strategyBehaviour=0;
    numberOfOccupiedRegion=0;
    phase="";
    turn=1;

}

ListofPlayer::ListofPlayer(int idPlayer,int victoryCoins,int population,
                           string specialPower,string race,bool decline)
{
    this->idPlayer = idPlayer;
    this->victoryCoins = victoryCoins;
    this->population =population ;
    this->specialPower = specialPower;
    this->race = race;
    this->decline=decline;
    decline_lock=0;
    strategyBehaviour=0;
    numberOfOccupiedRegion=0;
    phase="turn";
    turn=1;
}

int ListofPlayer::getTurn() const {
    return turn;
}

void ListofPlayer::setTurn(int turn) {
    ListofPlayer::turn = turn;
}

int ListofPlayer::getStrategyBehaviour() {
    return strategyBehaviour;
}

void ListofPlayer::setStrategyBehaviour(int strategyBehaviour) {
    this->strategyBehaviour = strategyBehaviour;
}

int ListofPlayer::getidPlayer()
{
    return idPlayer;

}

int ListofPlayer::getvictoryCoins(){

    return victoryCoins;
}


int ListofPlayer::getpopulation(){

    return population;
}

string ListofPlayer::getspecialPower(){

    return specialPower;
}
string ListofPlayer::getrace(){

    return race;
}

//void ListofPlayer::setidPlayer(int idPlayer)
//{
//    this->idPlayer=idPlayer;
//
//}

void ListofPlayer::setvictoryCoins(int victoryCoins){

    this->victoryCoins=victoryCoins;
}


void ListofPlayer::setpopulation(int population){

    this->population=population;
}

void ListofPlayer::setspecialpower( string specialPower){

    this->specialPower= specialPower;
}
void  ListofPlayer::setrace( string race){

    this->race=race;
}


ListofPlayer::~ListofPlayer(){}


void ListofPlayer::setDecline(bool decline) {
    ListofPlayer::decline = decline;
};

int ListofPlayer::getdecline_lock(){
    return decline_lock;
}

void ListofPlayer::setdecline_lock(int nb) {
    decline_lock=nb;
}

bool ListofPlayer::getDecline(){
    return decline;
}

int ListofPlayer::getNumberOfOccupiedRegion() {
    return numberOfOccupiedRegion;
}

void ListofPlayer::setNumberOfOccupiedRegion(int numberOfOccupiedRegion) {
    ListofPlayer::numberOfOccupiedRegion = numberOfOccupiedRegion;
}

const string &ListofPlayer::getPhase() const {
    return phase;
}

void ListofPlayer::setPhase(const string &phase) {
    ListofPlayer::phase = phase;
}



