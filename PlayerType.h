//
// Created by fok poon kai on 2018-04-06.
//

#ifndef COMP345P1_PLAYERTYPE_H
#define COMP345P1_PLAYERTYPE_H


#include <stdio.h>
#include "Player.h"
#include "ListofPlayer.h"
#include <iostream>
#include <vector>


using namespace std;

//the class is used to impliment the strategy pattern
class PlayerType{// this is an abtract class
public:
    /*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
    virtual void pickupRaceNSp(listOfPlayer *x) = 0;
    virtual void conquers(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr) = 0;
    virtual void  scores(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)  = 0;
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)=0;
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)=0;

};


#endif //COMP345P1_PLAYERTYPE_H
