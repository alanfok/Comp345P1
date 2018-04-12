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

    //   Player py;

    Veiwer  veiwer;
    //inherate in PlayerType Class
    virtual  void pickupRaceNSp(ListofPlayer *x);
    virtual  void conquers(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr);
    virtual void scores(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr);
    virtual  void firstEdge(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr);
    virtual void redeployment(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr);
    int totalNumberOfRegion;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int input;
    int input2;
    int lock;
    int toWhichRegion;
    int fromWhichRegion;
    bool redeployment_check;
    bool  fromregion;
    bool toregion;
    int regionPopulation;
    bool input_check;
    int putRedeploymentPopulation;
    int getRedeploymentPopulation;
};
#endif //COMP345P1_DEFENSIVEPLAYER_H
