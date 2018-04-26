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
    Veiwer veiwer;
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
    bool redeployment_check;
    int redeploymentPopulation;
    int regionPopulation;
    int toWhichRegion;
    int input;
    int fromWhichRegion;
    int putRedeploymentPopulation;
    int getRedeploymentPopulation;
    int lock;
    int input2;
};
#endif //COMP345P1_MODERATEPLAYER_H
