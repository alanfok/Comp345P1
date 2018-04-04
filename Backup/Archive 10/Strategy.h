//
// Created by fok poon kai on 2018-03-31.
//

#ifndef COMP345P1_PLAYERTYPE_H
#define COMP345P1_PLAYERTYPE_H
#include <stdio.h>
#include "Player.h"
#include "ListofPlayer.h"
#include <iostream>
#include "Observer.h"
#include <vector>
#include "PhaseObserver.h"


using namespace std;


class PlayerType{
public:
    virtual void pickupRaceNSp(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr) = 0;
    virtual void conquers(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr) = 0;
    virtual void  scores(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)  = 0;
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)=0;
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr)=0;

    protected:  
    private: 
};
 class AggressivePlayer: public PlayerType{
public: 
    AggressivePlayer(); 
    ~AggressivePlayer();

    Observer observer;
    PhaseObserver phase_observer;
    NodeRegion *nr_ptr;
    int total_number_of_region;
    int randomnumber;
    int playerid;
    int playerpop;
    bool conquer_check;
    bool Edgeoccupied;
    vector <int> storage;



    void pickupRaceNSp(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);

    virtual  void conquers(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void scores(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);

};


class DefensivePlayer:public PlayerType{
public: 
    DefensivePlayer(); 
    ~DefensivePlayer();
    Observer observer;
    PhaseObserver phase_observer;
 //   Player py;
 virtual  void pickupRaceNSp(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual  void conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    virtual void scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    virtual  void firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
    void redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr);
   int total_number_of_region;
    int randomnumber;
    int playerid;
    int playerpop;
    bool conquer_check;
    bool Edgeoccupied;
    vector <int> storage;

};

class ModeratePlayer:public PlayerType{
public: 
    ModeratePlayer();
    ~ModeratePlayer();
    Observer observer;
    PhaseObserver phase_observer;
   // Player py;
   virtual void pickupRaceNSp(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void conquers(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void scores(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    int total_number_of_region;
    int randomnumber;
    int playerid;
    int playerpop;
    bool conquer_check;
    bool Edgeoccupied;
    vector <int> storage;
};

//class HumanPlayer:public PlayerType{
//public: 
//    HumanPlayer(); 
//    ~HumanPlayer();
//    void pickupRaceNSp(listOfPlayer x,Player py);
//    void conquers(listOfPlayer x,Player py);
//    void scores(listOfPlayer x,Player py);
//    void firstEdge(listOfPlayer x,Player py);
//    void redeployment(listOfPlayer x,Player py);
//};
class RandomPlayer:public PlayerType{
public:
    RandomPlayer();
    ~RandomPlayer();
    Observer observer;
    PhaseObserver phase_observer;
//    Player py;
    void pickupRaceNSp(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void conquers(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void scores(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    void redeployment(listOfPlayer *x,Player py,vector <NodeRegion > *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    int total_number_of_region;
    int randomnumber;
    int playerid;
    int playerpop;
    bool conquer_check;
    bool Edgeoccupied;
    vector <int> storage;
    int randomnumberV2;



};
#endif //COMP345P1_PLAYERTYPE_H
