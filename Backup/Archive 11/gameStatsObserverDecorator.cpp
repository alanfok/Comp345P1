//
// Created by fok poon kai on 2018-04-03.
//

#include "gameStatsObserverDecorator.h"
#include "gameStatsObserver.h"
#include "Maps.h"
#include "Player.h"

void gameStatsObserverDecorator::get_turn_number(int turn) {
    cout << "TURN " << turn << " ";
}

/*void gameStatsObserverDecorator::update_region_control(vector <int> playercounter,int nbplayers) {
    int totalRegionNumber = m.nbMapRegions[nbplayers-2];
    // gets region number
    cout << "-------- Current Game Stats ---------" << endl;
    cout << "% of World Occupied by Each Player" <<endl;

    for(int x=0;x<nbplayers;x++) {
        cout << "Player " << x+1 << endl;
        cout << ((double)playercounter[x]/totalRegionNumber) * 100 << "%"  << endl;
    }
}
// claudia

void gameStatsObserverDecorator::region_counter(vector <int> playercounter,int nbplayers, Player player){

    for(int p=0;p < nbplayers ;p++) {
        playercounter[p] = 0;
    }

    for (int i=0;i< player.maploader.nbline ;i++){
        for(int y=0;y< nbplayers ;y++) {
            if(player.maploader.maps.pt[i][i]== y+1){
                playercounter[y]++;
            }
        }
    }//claudia
    gameStatsObserverDecorator::update_region_control(playercounter,nbplayers);//claudia

    for(int p=0;p< nbplayers ;p++) {
        playercounter[p] = 0;
    }
}*/
//claudia

