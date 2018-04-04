//
// Created by fok poon kai on 2018-04-01.
//

#include "Observer.h"
#include "PhaseObserver.h"
#include "gameStatsObserverDecorator.h"
#include "DominationObserverDecorator.h"
#include "HandsObserverDecorator.h"
#include "VictoryCoinsObserverDecorator.h"

PhaseObserver p;
gameStatsObserverDecorator game_stats_observer_decorator;
DominationObserverDecorator dominationObserverDecorator;
HandsObserverDecorator handsObserverDecorator;
VictoryCoinsObserverDecorator victoryCoinsObserverDecorator;


using namespace std;

/* put the object in the vector and keep it in the vector */

void Observer::attach(listOfPlayer ls) {
    phaseObserver.push_back(ls);
}

/* return the list of players that are playing the game*/

vector <listOfPlayer> Observer :: getPlayerList() {
    return phaseObserver;
}

/* Call this "main function" to updates all of the sub Decorators
   that display different information about the status of the players*/

void Observer :: update(vector <listOfPlayer> phaseObserver,vector <int> playercounter,
                        int nbplayers,string race, string specialpower, int nbpopulation
        ,int nb,Player py,int turn,string coin_status,string region_status,
                        vector <int> lostRegions , vector <listOfPlayer> vplayer ){
    game_stats_observer_decorator.get_turn_number(turn);
    p.race_picked(race , specialpower);
    handsObserverDecorator.player_cards(nbpopulation , nbplayers,vplayer);
    p.update_region_conquer(phaseObserver,region_status,nb);
    p.update_coin(coin_status, nb);
    victoryCoinsObserverDecorator.coins_scored(nb,py);
    dominationObserverDecorator.regions_owned(playercounter,nbplayers, py);
    dominationObserverDecorator.regions_lost(lostRegions,nbplayers);
    // Calling many functions coming from different classes that display information
    // about what is happening in the current turn
}

/* Erase the object from the vector */

void Observer::detach(listOfPlayer ls) {
    for (int i = 0; i <phaseObserver.size(); ++i) {
        if(ls.getidPlayer() == phaseObserver[i].getidPlayer()){
            phaseObserver.erase(phaseObserver.begin()+i);
        }
    }
}


