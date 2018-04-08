//
// Created by fok poon kai on 2018-04-07.
//

#include "VictoryCoinsObserverDecorator.h"
void VictoryCoinsObserverDecorator::Update(ListofPlayer *lp) {
    cout<<"Player: "<<lp->getidPlayer()<<" has "<<lp->getvictoryCoins()<<" victory coin"<<endl;
}