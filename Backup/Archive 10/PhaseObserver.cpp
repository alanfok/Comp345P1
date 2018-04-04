//
// Created by fok poon kai on 2018-04-02.
//

#include "PhaseObserver.h"

void PhaseObserver::update_coin(vector <listOfPlayer> phaseObserver) {
    for (int i = 0; i < phaseObserver.size(); ++i) {
        cout<<"Player "<<phaseObserver[i].getidPlayer()
            <<" collect some coins"<<endl;
    }
}

void PhaseObserver::update_conquer(vector <listOfPlayer> phaseObserver) {
    for (int i = 0; i < phaseObserver.size(); ++i) {
        cout<<"Player "<<phaseObserver[i].getidPlayer()
            <<" conquer some regions"<<endl;
    }
}

void PhaseObserver::race_picked(string race ,string specialpower) {
    cout << "The race picked is : " << race << " "
         << specialpower << endl;
}

void PhaseObserver::population(int nbpopulation) {
    cout << "You have " << nbpopulation << " population" << endl;
}

void PhaseObserver::get_player_infomation(int nb, Player py) {
    nb-=1;
    cout<<"player "<<py.vplayer[nb].getidPlayer()<< " has "
        << py.vplayer[nb].getvictoryCoins()<< " coin(s)"<<endl;

}

void PhaseObserver::get_turn_number(int turn) {
    cout << "TURN " << turn << " ";
}
