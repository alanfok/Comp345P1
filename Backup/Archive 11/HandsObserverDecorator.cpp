//
// Created by fok poon kai on 2018-04-03.
//

#include "HandsObserverDecorator.h"

void HandsObserverDecorator::player_cards(int population_number , int nbplayers) {
    for(int x=0;x<nbplayers;x++) {
        cout << "You have " << population_number << " population" << endl;
    }

}
