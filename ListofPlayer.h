//
// Created by fok poon kai on 2018-03-09.
//


#ifndef COMP345P1_NODEPLAYER_H
#define COMP345P1_NODEPLAYER_H
#include <string>
#include "list"
#include "Subject.h"


using namespace std;

class ListofPlayer{
public:

    ListofPlayer();
    ListofPlayer(int idPlayer,int victoryCoins,int population,
                 string specialPower,string race,bool decline);
    ~ListofPlayer();

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

    const string &getPhase() const;

    void setPhase(const string &phase);

    void setStrategyBehaviour(int strategyBehaviour);

    int getTurn() const;

    void setTurn(int turn);


private:
    int idPlayer;


    int numberOfOccupiedRegion;
    int victoryCoins;
    int population;
    bool decline;
    int decline_lock=0;
    int turn=1;
    string specialPower;
    string race;
    int strategyBehaviour;
    string phase;
};
#endif //COMP345P1_NODEPLAYER_H
