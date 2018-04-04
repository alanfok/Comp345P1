//
// Created by fok poon kai on 2018-04-03.
//

#include "DominationObserverDecorator.h"
#include <vector>
#include <iostream>

using namespace std;
Maps m;

/**
 * This function returns the percentage of regions lost by each player
 * */

void DominationObserverDecorator :: regions_lost(vector <int> lostRegions, int nbplayers ) {

    for(int x=0;x<lostRegions.size();x++) {
        if(lostRegions[x] == 1) {
            one++;
        }
        else if(lostRegions[x] == 2){
            two++;
        }
        else if(lostRegions[x] == 3){
            three++;
        }
        else if(lostRegions[x] == 4){
            four++;
        }
        else if(lostRegions[x] == 5){
            five++;
        }
    }

    int numberregionlost[5] = {one,two,three,four,five};

    cout << "% of Regions Lost by Each Player" <<endl;

    for(int y = 0;y < nbplayers;y++) {
        cout <<"Player " << y+1 << endl;
        cout << ((double)numberregionlost[y]/23) * 100 << "%" << endl;
    }

}

/**
 *  This function shows the percentage of regions currently conquered by each player
 * */

void DominationObserverDecorator::update_region_control(vector <int> playercounter,int nbplayers) {
    int totalRegionNumber = m.nbMapRegions[nbplayers-2];
    // gets region number
    //br();
    cout << "-------- Current Game Stats ---------" << endl;
    cout << "% of World Occupied by Each Player" <<endl;

    for(int x=0;x<nbplayers;x++) {
        cout << "Player " << x+1 << endl;
        cout << ((double)playercounter[x]/totalRegionNumber) * 100 << "%"  << endl;
    }
}

/**
 *  This function ensures that when update_region_control is called, no extra redundant
 *  elements are added to the vector.
 * */

void DominationObserverDecorator::regions_owned(vector <int> playercounter,int nbplayers, Player player){

    for(int p=0;p < nbplayers ;p++) {
        playercounter[p] = 0;
    }

    for (int i=0;i< player.maploader.nbline ;i++){
        for(int y=0;y< nbplayers ;y++) {
            if(player.maploader.maps.pt[i][i]== y+1){
                playercounter[y]++;
            }
        }
    }
    DominationObserverDecorator::update_region_control(playercounter,nbplayers);//claudia

    for(int p=0;p< nbplayers ;p++) {
        playercounter[p] = 0;
    }
}

