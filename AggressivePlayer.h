//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_AGGRESSIVE_H
#define COMP345P1_AGGRESSIVE_H

#include "PlayerType.h"

class AggressivePlayer: public PlayerType{
public: 
    AggressivePlayer(); 
    ~AggressivePlayer();

    Observer observer;
    PhaseObserver phase_observer;
    NodeRegion *nr_ptr;
    int totalNumberOfRegion;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int fromWhichRegion;
    int toWhichRegion;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(listOfPlayer *x);
    virtual  void conquers(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void scores(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);

};
#endif //COMP345P1_AGGRESSIVE_H
