//
// Created by fok poon kai on 2018-04-02.
//

#include "PhaseObserver.h"
/*
 * This function gets the status of the coins owned by each player. It indicated if the player gains,
 * looses or retains the coins he has
 * */

void PhaseObserver::update_coin(string coin_status ,int nb) {
    cout<<"Player "<< nb << coin_status << endl;
}

/*
 * This function gets the status of the regions owned by each player . It indicated if the player gains,
 * looses or retains the regions he has
 * */

void PhaseObserver::update_region_conquer(vector <listOfPlayer> phaseObserver, string region_status, int nb) {
    cout<<"Player "<< nb
        << region_status <<endl;
}

/*
 * This function gets the status of the regions owned by each player. It indicates when the player
 * conquers regions.
 * */

void PhaseObserver::update_conquer(vector <listOfPlayer> phaseObserver) {
    for (int i = 0; i < phaseObserver.size(); ++i) {
        cout<<"Player "<< phaseObserver[i].getidPlayer() << " conquers some regions" <<endl;
    }
}

/*
 * This function gets the status of the race picked by the player
 * */
void PhaseObserver::race_picked(string race ,string specialpower) {
    cout << "The race picked is : " << race << " "
         << specialpower << endl;
}




