//
// Created by fok poon kai on 2018-04-07.
//

#include "StatisticsObserver.h"
StatisticsObserve::StatisticsObserve() {

}
void StatisticsObserve::update(vector<ListofPlayer> *lp_vPtr,int numberOfRegion){
    for (int i = 0; i < lp_vPtr->size(); ++i) {

        cout<<(*lp_vPtr)[i].getidPlayer()<<" has "<<(*lp_vPtr)[i].getNumberOfOccupiedRegion()<<" and"<<
            (((float)(*lp_vPtr)[i].getNumberOfOccupiedRegion()/numberOfRegion))*100<<" % of the regions"<<endl;
    }
}