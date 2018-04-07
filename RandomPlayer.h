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

//    Player py;
//inherate in PlayerType Class
    void pickupRaceNSp(ListofPlayer *x);
    void conquers(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    void scores(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    void firstEdge(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    void redeployment(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
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
