//
// Created by fok poon kai on 2018-04-07.
//

#include "HandsObserverDecorator.h"
void HandsObserverDecorator::Update(ListofPlayer *lp) {
   cout<<"Player :"<< lp->getidPlayer()<<" race "<<lp->getrace()<<", has "<<lp->getpopulation()<<"."<<endl;
}