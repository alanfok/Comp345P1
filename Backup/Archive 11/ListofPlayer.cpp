//
// Created by fok poon kai on 2018-03-09.
//
#include "ListofPlayer.h"

listOfPlayer::listOfPlayer()
{
    idPlayer = 0;
    victoryCoins = 0;
    population =0 ;
    specialPower = "";
    race = "";
    decline=false;
    decline_lock=0;

}

listOfPlayer::listOfPlayer(int idPlayer,int victoryCoins,int population,
                           string specialPower,string race,bool decline)
{
    this->idPlayer = idPlayer;
    this->victoryCoins = victoryCoins;
    this->population =population ;
    this->specialPower = specialPower;
    this->race = race;
    this->decline=decline;
    decline_lock=0;
}

int listOfPlayer::getidPlayer()
{
    return idPlayer;

}

int listOfPlayer::getvictoryCoins(){

    return victoryCoins;
}


int listOfPlayer::getpopulation(){

    return population;
}

string listOfPlayer::getspecialPower(){

    return specialPower;
}
string listOfPlayer::getrace(){

    return race;
}
//string NodePlayer::getpointedears(){
//
//    return degreeofpointy;
//}//claudia


void listOfPlayer::setidPlayer(int idPlayer)
{
    this->idPlayer=idPlayer;

}

void listOfPlayer::setvictoryCoins(int victoryCoins){

    this->victoryCoins=victoryCoins;
}


void listOfPlayer::setpopulation(int population){

    this->population=population;
}

void listOfPlayer::setspecialpower( string specialPower){

    this->specialPower= specialPower;
}
void  listOfPlayer::setrace( string race){

    this->race=race;
}


listOfPlayer::~listOfPlayer(){}

bool listOfPlayer::isDecline() const {
    return decline;
}

void listOfPlayer::setDecline(bool decline) {
    listOfPlayer::decline = decline;
};

int listOfPlayer::getdecline_lock(){
    return decline_lock;
}

void listOfPlayer::setdecline_lock(int nb) {
    decline_lock=nb;
}

bool listOfPlayer::getDecline(){
    return decline;
}