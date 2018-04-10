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


    NodeRegion *nr_ptr;
    int totalNumberOfRegion;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    int fromWhichRegion;
    int toWhichRegion;
    bool  fromregion;
    bool toregion;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(ListofPlayer *x);
    virtual  void conquers(ListofPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void scores(ListofPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void firstEdge(ListofPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void redeployment(ListofPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<ListofPlayer> *lp_vtr);

};
#endif //COMP345P1_AGGRESSIVE_H
