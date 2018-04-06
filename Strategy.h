//
// Created by fok poon kai on 2018-03-31.
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

protected:  
private: 
};

//for player who choose the aggressive behaiver
 class AggressivePlayer: public PlayerType{
public: 
    AggressivePlayer(); 
    ~AggressivePlayer();

    Observer observer;
    PhaseObserver phase_observer;
    NodeRegion *nr_ptr;
    int totalNumberOfRegion;
    int regionid;
    int playerID;
    int playerPopulation;
    bool conquer_check;
    bool Edgeoccupied;
    vector <int> storage;
    int fromWhichRegion;
    int toWhichRegion;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(listOfPlayer *x);
    virtual  void conquers(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void scores(listOfPlayer *x,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void firstEdge(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);
    virtual void redeployment(listOfPlayer *x,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vtr);

};

//for player who choose the Defensive behaiver
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
    vector <int> storage;
    int firstLock=0;
    int toWhichRegion;
    int fromWhichRegion;
    bool redeployment_check;
    int input;
    int redeploymentPopulation;
    int regionPopulation;

};
//for player who choose the Moderate(decline) behaiver
class ModeratePlayer:public PlayerType{
public: 
    ModeratePlayer();
    ~ModeratePlayer();
    Observer observer;
    PhaseObserver phase_observer;
    // Player py;
    //inherate in PlayerType Class
    virtual void pickupRaceNSp(listOfPlayer *x);
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



//for player who choose the Random behaiver

class RandomPlayer:public PlayerType{
public:
    RandomPlayer();
    ~RandomPlayer();
    Observer observer;
    PhaseObserver phase_observer;
//    Player py;
//inherate in PlayerType Class
    void pickupRaceNSp(listOfPlayer *x);
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
