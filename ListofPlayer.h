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
    int getdecline_lock();
    int getNumberOfOccupiedRegion() const;
    int getStrategyBehaviour();



//set
    void setidPlayer(int idPlayer);
    void setvictoryCoins(int victoryCoins);
    void setpopulation(int population);
    void setspecialpower(string specialPower);
    void setrace(string race);
    void setdecline_lock(int nb);
    void setNumberOfOccupiedRegion(int numberOfOccupiedRegion);


    void setStrategyBehaviour(int strategyBehaviour);

private:
    int idPlayer;


    int numberOfOccupiedRegion;
    int victoryCoins;
    int population;
    bool decline;
    int decline_lock=0;

    string specialPower;
    string race;
    int strategyBehaviour;
};
#endif //COMP345P1_NODEPLAYER_H
