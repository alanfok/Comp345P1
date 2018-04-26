//
// Created by fok poon kai on 2018-04-07.
//

#include "PhaseObserver.h"


PhaseObserver::PhaseObserver() {



}
void PhaseObserver::update(ListofPlayer *lp){
 phase=lp->getPhase();

 //cout<<phase<<endl;
 if(phase.compare("turn")==0){
  cout<<"-------------Player "<<lp->getidPlayer()<<": turn "<<lp->getTurn()<<" .---------------------------------"<<endl;
 }
 if(phase.compare("coin")==0){
  cout<<"-------------Player "<<lp->getidPlayer()<<": Scores some victory coins.-------------"<<endl;
 }
 if(phase.compare("conquer")==0){
  cout<<"-------------Player "<<lp->getidPlayer()<<"conquer some regions.-------------"<<endl;
 }




}