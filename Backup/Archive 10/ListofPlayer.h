//
// Created by fok poon kai on 2018-03-09.
//

#ifndef COMP345P1_NODEPLAYER_H
#define COMP345P1_NODEPLAYER_H
#include <string>
#include "list"


using namespace std;

class listOfPlayer{
public:
    int idPlayer;

    bool isDecline() const;

    int victoryCoins;
    int population;
    bool decline;

    string specialPower;
    string race;
    listOfPlayer();
    listOfPlayer(int idPlayer,int victoryCoins,int population,
               string specialPower,string race,bool decline);
    ~listOfPlayer();

//get
    int getidPlayer();

    void setDecline(bool decline);
    bool getDecline();
    int getvictoryCoins();
    int getpopulation();
    string getspecialPower();
    string getrace();



//set
    void setidPlayer(int idPlayer);
    void setvictoryCoins(int victoryCoins);
    void setpopulation(int population);
    void setspecialpower(string specialPower);
    void setrace(string race);




};
#endif //COMP345P1_NODEPLAYER_H