//
// Created by Claudia Feochari on 2018-04-02.
//
#include "HandsObserverDecorator.h"
#include "Player.h"

/**
 *  This function gets the number of cards (or population) each player owns
 * */

void HandsObserverDecorator::player_cards(int population_number , int nbplayers , vector <listOfPlayer> vplayer) {

    for(int x=0;x<nbplayers;x++) {
        cout << "You have " << vplayer[x].getpopulation() << " population" << endl;
    }

}