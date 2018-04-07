//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_RANDOMPLAYER_H
#define COMP345P1_RANDOMPLAYER_H

#include "PlayerType.h"
class RandomPlayer:public PlayerType{
public:
    RandomPlayer();
    ~RandomPlayer();
    Observer observer;
    PhaseObserver phase_observer;
//    Player py;
//inherate in PlayerType Class
    void pickupRaceNSp(listOfPlayer *x);
    void conquers(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void scores(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void redeployment(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    int totalNumberOfRegion;

    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int toWhichRegion;
    int fromWhichRegion;
    int randomnumberV2;
    bool redeployment_check;
    int redeploymentPopulation;
    int regionPopulation;
    int input;
    int firstLock;
};
#endif //COMP345P1_RANDOMPLAYER_H
