//
// Created by fok poon kai on 2018-04-01.
//

#include "Observer.h"
#include "PhaseObserver.h"
#include "gameStatsObserver.h"

PhaseObserver p;
gameStatsObserver gso;
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
        ,int nb,Player py,int turn){
    p.get_turn_number(turn);
    p.race_picked(race , specialpower);
    p.population(nbpopulation);
    p.update_conquer(phaseObserver);
    p.update_coin(phaseObserver);
    p.get_player_infomation(nb,py);
    gso.region_counter(playercounter,nbplayers, py);
    //gso.update_region_control(playercounter,nbplayers);
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
