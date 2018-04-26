//
// Created by fok poon kai on 2018-03-21.
//

#include "Veiwer.h"




void Veiwer::getPlayerInfoAndShowOccupiedregion(int nb,Player py) {
    get_player_infomation( nb, py);
    show_region_are_occupied( nb, py);
}


void Veiwer::get_player_infomation(int nb, Player py) {
    nb-=1;
    cout<<"player "<<py.vplayer[nb].getidPlayer()<< " has "<<py.vplayer[nb].getpopulation()<< "population and "
        << py.vplayer[nb].getvictoryCoins()<< " coins"<<endl;



}


void Veiwer::show_region_are_occupied(int nb, Player py) {
    for(int i=0;i<py.vnodeRegion.size();i++){
        if(py.vnodeRegion[i].getid_player()==nb){
            cout << "the region status "<< i+1 <<" is " <<py.vnodeRegion[i].getregion_status()<<" has "<<
                 py.vnodeRegion[i].getregion_population()<<" populations and occupied by Player " <<py.vnodeRegion[i].getid_player()<<endl;
        }
    }
}

void Veiwer::showAllPlayerInformation(Player py) {
    for (int i = 0; i < py.vplayer.size(); ++i) {
        cout<<"player "<<py.vplayer[i].getidPlayer()<< " has "<<py.vplayer[i].getpopulation()<< "population and "
            << py.vplayer[i].getvictoryCoins()<< " coins"<<endl;
    }
}