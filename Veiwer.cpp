//
// Created by fok poon kai on 2018-03-21.
//

#include "Veiwer.h"




void Veiwer::get_individual_region_info(int nb,Player py) {
    cout << "the region status is " <<py.vnodeRegion[nb].getregion_status()<<" has "<<
         py.vnodeRegion[nb].getregion_population()<<" populations and occupied by Player" <<py.vnodeRegion[nb].getid_player()<<endl;




}


void Veiwer::get_player_infomation(int nb, Player py) {
    nb-=1;
    cout<<"player "<<py.vplayer[nb].getidPlayer()<< " has "<<py.vplayer[nb].getpopulation()<< " and "
        << py.vplayer[nb].getvictoryCoins()<< "coin"<<endl;



}


void Veiwer::show_region_are_occupied(int nb, Player py) {
    for(int i=0;i<py.vnodeRegion.size();i++){
        if(py.vnodeRegion[i].getid_player()==nb){
            cout << "the region status "<< i+1 <<"is " <<py.vnodeRegion[i].getregion_status()<<" has "<<
                 py.vnodeRegion[i].getregion_population()<<" populations and occupied by Player " <<py.vnodeRegion[i].getid_player()<<endl;
        }
    }
}

