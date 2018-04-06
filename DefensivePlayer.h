//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_DEFENSIVEPLAYER_H
#define COMP345P1_DEFENSIVEPLAYER_H

#include "PlayerType.h"


class DefensivePlayer:public PlayerType{
public: 
    DefensivePlayer(); 
    ~DefensivePlayer();
    Observer observer;
    PhaseObserver phase_observer;
    //   Player py;


    //inherate in PlayerType Class
    virtual  void pickupRaceNSp(listOfPlayer *x);
    virtual  void conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    virtual void scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    virtual  void firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    void redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    int totalNumberOfRegion;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int firstLock=0;
    int toWhichRegion;
    int fromWhichRegion;
    bool redeployment_check;
    int input;
    int redeploymentPopulation;
    int regionPopulation;

};
#endif //COMP345P1_DEFENSIVEPLAYER_H
