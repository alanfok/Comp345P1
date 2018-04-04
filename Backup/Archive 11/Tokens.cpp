//
// Created by fok poon kai on 2018-02-03.
//

#include "Tokens.h"
#include <ctime>
#include <cstdlib>

#include <stdlib.h>
#include <stdio.h>

void Tokens ::occupied(int region, int idOfplayer ,int invade_region) {

    // cout<<maploader.maps.pt[0][1]<<endl;

    if(maploader.maps.pt[region][region]==0){
        maploader.maps.pt[region][region]=idOfplayer;
    }
    else if(maploader.maps.pt[region][region]!=0){

        invade(region, idOfplayer ,invade_region);


    }
    else{
        cout<<"the region is occupied by other player"<<endl;
    }

};
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////



void Tokens ::invade(int region,int idOfplayer,int invadeToRegion) {

// means  the region not open and the region not player himself and it linking
    if((maploader.maps.pt[invadeToRegion][invadeToRegion]!=idOfplayer)
       &&(maploader.maps.pt[region][invadeToRegion]==1)
       &&(maploader.maps.pt[invadeToRegion][region]==1)){
        maploader.maps.pt[invadeToRegion][invadeToRegion]=idOfplayer;
    }else{
        cout<<"the region is occupied by other player"<<endl;
        //edgechecking=false;
    }

}




void Tokens::point_del() {
    maploader.maps.pointer_del();
    maploader.pointer_del();
    cout<<"end game"<<endl;

}


void Tokens::prints() {
    for (int i=0;i<maploader.nbline;i++){
        if(i<9){
            cout<<" ";
        }
        cout << i+1 <<" ";
        cout << maploader.region_status[i]<< " ";
        for (int j = 0; j < maploader.nbline; ++j) {
            cout<<maploader.maps.pt[i][j]<<" ";
        }
        cout << maploader.adjact[i]<<" ";
        cout << maploader.losttride[i]<<" ";
        cout<<endl;
    }



}

int myrandom (int i) { return std::rand()%i;}
void Tokens::enter_race_sp_to_vector(){
    srand(time(NULL));

    int bunny_name_index = rand() % 14 ;
    //bunny_name_index;
    int ran;
    //cout << rand() << endl;

    // cout<<"test"<<race_randam_picking1<<endl;

    random_shuffle(racess.begin(),racess.end(),myrandom);
    random_shuffle(special_power.begin(),special_power.end(),myrandom);
    for (int i = 0; i < 13; ++i) {
        vrace.push_back(racess[i]);


    }
    //racess[(race_randam_picking1 +i)% 14]
    for (int j = 0; j <13 ; ++j) {
        vspecialpower.push_back( special_power[j]);
    }
    special_power.clear();
    racess.clear();
    special_power.shrink_to_fit();
    racess.shrink_to_fit();
}

void Tokens::shift(int nb_of_race) {
    temp_of_shift=nb_of_race-1;//index alway -1 that player enter
    for (int i = temp_of_shift; i < vrace.size(); i++) {
        vrace[i]=vrace[i+1];
        vspecialpower[i]=vspecialpower[i+1];
    }

}

string Tokens::getvrace(int nb_of_race) {
    return  vrace[nb_of_race-1];
}

string Tokens::getvspecialpower(int nb_of_race) {

    return vspecialpower[nb_of_race-1];
}

void  Tokens::vrace_vspecialpower_print() {
    //cout << "HELPME" << endl;
    for (int j = 0; j < 6; ++j) {
        cout<<j+1<<" "<<vrace[j]<<" "<<vspecialpower[j]<<endl;
    }
}
//Important
int Tokens::race_population_determind(string race,string specialpower){

    if(race.compare("Amazons")==0){
        race_population+=6;
        //cout << "AMAZONS";
    }
    if(race.compare("Dwarves")==0){
        race_population+=3;
        //cout << "DWARVES";
        //cout << race_population;
    }
    if(race.compare("Elves")==0){
        race_population+=6;
        //cout << "ELVES";
        //cout << race_population;
    }
    if(race.compare("Ghouls")==0){
        race_population+=5;
        //cout << "GHOULS";
        //cout << race_population;
    }
    if(race.compare("Giants")==0){
        race_population+=6;
        //cout << "GIANTs";
        //cout << race_population;
    }
    if(race.compare("Ratmen")==0){
        race_population+=8;
        //cout << "RATMEN";
        //cout << race_population;
    }
    if(race.compare("Skeletons")==0){
        race_population+=6;
        //cout << "SKELETONS";
        //cout << race_population;
    }
    if(race.compare("Sorecerers")==0){
        race_population+=5;
        //cout << "SORCERERS";
        //cout << race_population;
    }
    if(race.compare("Tritons")==0){
        race_population+=3;
        //cout << "TRITONS";
        //cout << race_population;
    }
    if(race.compare("Halfings")==0){
        race_population+=6;
        //cout << "HALFINGS";
        //cout << race_population;
    }
    if(race.compare("Human")==0){
        race_population+=5;
        //cout << "HUMAN";
        //cout << race_population;
    }
    if(race.compare("Orcs")==0){
        race_population+=5;//cout << "ORCS";
        //cout << race_population;
    }
    if(race.compare("Trolls")==0){
        race_population+=5;//cout << "TROLLS";
        //cout << race_population;
    }
    if(race.compare("Wizards")==0){
        race_population+=5;//cout << "WIZARDS";
        //cout << race_population;
    }
    ///////////////////sp//////////
    if(specialpower.compare("Alchemist")==0){
        race_population+=4;
        //cout << "Alchemist" << endl;
        //cout << race_population << endl;
    }
    if(specialpower.compare("Berserk")==0){
        race_population+=4;
        //cout << "Berserk" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Bivouacking")==0){
        race_population+=5;
        //cout << "Bivouacking" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Commando")==0){
        race_population+=4;
        //cout << "Commando" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Diplomat")==0){
        race_population+=5;
        //cout << "Diplomat" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Dragon_Master")==0){
        race_population+=5;
        //cout << "Dragon_Master" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Flying")==0){
        race_population+=5;
        //cout << "Flying" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Forest")==0){
        race_population+=4;
        //cout << "Forest" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Fortified")==0){
        race_population+=3;
        //cout << "Fortified" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Heroic")==0){
        race_population+=5;
        //cout << "Heroic" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Hill")==0){
        race_population+=4;
        //cout << "Hill" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Merchant")==0){
        race_population+=2;
        //cout << "Merchant" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Mounted")==0){
        race_population+=5;
        //cout << "Mounted" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Pillaging")==0){
        race_population+=5;
        //cout << "Pillaging" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Seafaring")==0){
        race_population+=5;
        //cout << "Seafaring" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Spirit")==0){
        race_population+=5;
        //cout << "Spirit" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Stout")==0){
        race_population+=4;
        //cout << "Stout" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Swamp")==0){
        race_population+=4;
        //cout << "Swamp" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Underworld")==0){
        race_population+=5;
        //cout << "Underworld" << endl;
        //cout << race_population;
    }
    if(specialpower.compare("Wealthy")==0){
        race_population+=4;
        //cout << "Wealthy" << endl;
        //cout << race_population;
    }
    //cout << race_population << endl;
    return race_population;
}
////////////////////////////////////////////////////////////
int Tokens::getRace_population(){
    return race_population;

}

void Tokens::setRace_population(int number){
    race_population=number;

}



bool Tokens::edgecheck(int from, int to) {
    if((maploader.maps.pt[from][to]==1)
       &&(maploader.maps.pt[to][from]==1)){
        return true;
    }else{
        return false;
    }
}
/*if from  is x and to is y , we will check matrix x,y is 1 and y,x is 1 the confirm that the have a board or not and
 also check the region is occupied by himself or Not
 */

void Tokens::invade_v2(int pyid, int regionid) {
    maploader.maps.pt[regionid][regionid]=pyid;
}
