// Created by Claudia Feochari on 2018-04-02.
//

#include "VictoryCoinsObserverDecorator.h"

void VictoryCoinsObserverDecorator::coins_scored(int nb, Player py)
{
    nb-=1;
    cout<<"player "<<py.vplayer[nb].getidPlayer()<< " has "
        << py.vplayer[nb].getvictoryCoins()<< " coin(s)"<<endl;
}