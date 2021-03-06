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
    Veiwer veiwer;

    NodeRegion *nr_ptr;
    int lock;
    int totalNumberOfRegion;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int fromWhichRegion;
    int toWhichRegion;
    bool  fromregion;
    bool toregion;
    int input;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(ListofPlayer *x);
    virtual  void conquers(ListofPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void scores(ListofPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void firstEdge(ListofPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void redeployment(ListofPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<ListofPlayer> *lp_vtr);

};
#endif //COMP345P1_AGGRESSIVE_H
