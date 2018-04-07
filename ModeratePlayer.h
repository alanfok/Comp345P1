//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_MODERATEPLAYER_H
#define COMP345P1_MODERATEPLAYER_H

#include "PlayerType.h"
class ModeratePlayer:public PlayerType{
public: 
    ModeratePlayer();
    ~ModeratePlayer();

    // Player py;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(ListofPlayer *x);
    virtual void conquers(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void scores(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void firstEdge(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    virtual void redeployment(ListofPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<ListofPlayer> *lp_vtr);
    int totalNumberOfRegion;
    int randomnumber;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;

    int toWhichRegion;
    int input;
    int fromWhichRegion;
};
#endif //COMP345P1_MODERATEPLAYER_H
