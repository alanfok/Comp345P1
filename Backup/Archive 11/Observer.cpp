//
// Created by fok poon kai on 2018-04-01.
//

#include "Observer.h"
#include "PhaseObserver.h"
#include "gameStatsObserverDecorator.h"
#include "DominationObserverDecorator.h"
#include "HandsObserverDecorator.h"

PhaseObserver p;
gameStatsObserverDecorator gso;
DominationObserverDecorator d;
HandsObserverDecorator h;

using namespace std;
void Observer::attach(listOfPlayer ls) {
    phaseObserver.push_back(ls);
    // to do : attach gameStatsObserver
}

vector <listOfPlayer> Observer :: getPlayerList() {
    return phaseObserver;
}

// claudia : Alan, we dont need attach. that is only for model , we are using view
void Observer :: update(vector <listOfPlayer> phaseObserver,vector <int> playercounter,
                        int nbplayers,string race, string specialpower, int nbpopulation
        ,int nb,Player py,int turn,string coin_status,string region_status,
                        vector <int> lostRegions ){
    gso.get_turn_number(turn);
    p.race_picked(race , specialpower);
    h.player_cards(nbpopulation , nbplayers);
    //p.population(nbpopulation);
    p.update_region_conquer(phaseObserver,region_status,nb);
    p.update_coin(phaseObserver,coin_status, nb);
    p.get_player_infomation(nb,py);
    d.regions_owned(playercounter,nbplayers, py);
    d.regions_lost(lostRegions,nbplayers);
}
//claudia

void Observer::detach(listOfPlayer ls) {
    for (int i = 0; i <phaseObserver.size(); ++i) {
        if(ls.getidPlayer() == phaseObserver[i].getidPlayer()){
            phaseObserver.erase(phaseObserver.begin()+i);
        }
    }
}
//claudia

