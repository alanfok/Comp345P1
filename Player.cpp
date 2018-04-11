//
// Created by fok poon kai on 2018-02-03.
//

#include "Player.h"

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

//////////// new add  ////////// please test//////////


void Player::del_pointer() {

    tokens.point_del();
}


int Player::getthrowdie() {
    die.throwsOne();
    return die.dice1;

}




void Player::set_vnodeRegion_Vector(int nbline) {
    ;
    for (int i = 0; i < maploader.nbline; i++) {
        isLostTribe = false;
        if (maploader.losttride[i].compare("_LosTri_") == 0) {
            isLostTribe = true;
            NodeRegion nodeRegion(i + 1, 1, maploader.region_status[i], "", "", isLostTribe, 0);
            // the LostTribe Costs 1 Population
            vnodeRegion.push_back(nodeRegion);
        } else {
            NodeRegion nodeRegion(i + 1, 0, maploader.region_status[i], "", "", isLostTribe, 0);
            vnodeRegion.push_back(nodeRegion);
        }

    }
}

void Player::pickup(int i, int vic , int p , string specialPower, string race,bool decline)  {

    ListofPlayer ListofPlayer(i + 1, vic,p,
                              specialPower,
                              race, decline);

    vplayer.push_back(ListofPlayer);//push into veco


}



void Player::token_sort() {    // sorting ny players coin

   cleanUpsortbyvplayercoin();
    for (int i = 300; i >= 0; i--) {
        for(int j=0 ; j<vplayer.size();j++) {
            if(vplayer[j].getvictoryCoins()==i){
                sortbyvplayercoin.push_back(vplayer[j]);
            }
        }
    }
}

void Player::declare_winner(){
    bool lock =false;
        for (int i = 300; i >= 0; i--) {
            if(lock==true){
                break;
            }
            for(int j=0 ; j<vplayer.size();j++) {
                if(lock==true){
                    break;
                }
                if(vplayer[j].getvictoryCoins()==i){
                    cout <<vplayer[j].getidPlayer()<<"is winner"<<endl;
                    lock=true;
                    break;
                }
            }
        }


}


int Player::special_power_pop_cost_deternment(int playerid, int regoinid) {
    if(vplayer[playerid].getspecialPower().compare("Commando")==0){
        return 1;
    } else if(vplayer[playerid].getspecialPower().compare("Mounted")==0&&
              (vnodeRegion[regoinid].getregion_status().compare("____plain__")==0||
               vnodeRegion[regoinid].getregion_status().compare("_____farm__"))){
        return 1;
    } else{
        return 2;}

}

//void Player::check_region_is_zero_pop(int region) {
//    if (vnodeRegion[region].getregion_population()==0){
//        vnodeRegion[region].setid_player(0);//erase the regionid data
//        vnodeRegion[region].setplayer_race("");//erase the regionrace data
//        vnodeRegion[region].setplayer_specialpower("");  //erase the regionsp data
//    }
//}

void Player::redeployment(int region, int Idofplayer, int pop) {
    if(vnodeRegion[region].getid_player()==Idofplayer){// if ther
        int temp = vnodeRegion[region].getregion_population();
        int temppy = vplayer[Idofplayer-1].getpopulation();
        if(temppy>=pop) {//player pop has to be more or = than pop u wanna put in
            vnodeRegion[region].setregion_population(temp + pop);//+the region pop and yr pop u put
            vplayer[Idofplayer - 1].setpopulation(temppy - pop);//- the pop u put
        }else{
            cout<<"You don't have enough population"<<endl;
        }
    }else{//the region is not the one that user occupied
        cout<<"You haven't occupied this region."<<endl;
    }
}


void Player::population_costv2(int playerid,int regionid){
    cost_of_population=special_power_pop_cost_deternment(playerid,regionid);
    cost_of_population+=vnodeRegion[regionid].getregion_population();
    if(vnodeRegion[regionid].getregion_status().compare("_mountain__")==0){
        cost_of_population+=1;
        cout<<"mountain cost 1 more popluation"<<endl;
    }
    if(maploader.losttride[regionid].compare("_LosTri_")==0){
        cost_of_population+=1;
        cout<<"lost tride cost 1 more popluation"<<endl;
    }
}


void Player::conquers_v4(ListofPlayer *lp,vector <NodeRegion> *nr_vPtr,int pop,int regionid){
    (*nr_vPtr)[regionid].setregion_population(pop);//←reset the regional object to new population
    (*nr_vPtr)[regionid].setid_player(lp->getidPlayer());//←reset the regional object to new Player ID
    (*nr_vPtr)[regionid].setplayer_race(lp->getrace());//←reset the regional object to new Player population
    (*nr_vPtr)[regionid].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power

    //cout<<lp->getNumberOfOccupiedRegion()<<endl;
   lp->setNumberOfOccupiedRegion(lp->getNumberOfOccupiedRegion()+1);

}


void Player::returnToPreviousPlayer(vector<NodeRegion> *nr_vPtr, vector<ListofPlayer> *vectorListOfPlayerPointer, int regionid) {
    if( (*nr_vPtr)[regionid].getid_player()!=0) {
        int temp_number = (*nr_vPtr)[regionid].getid_player();//get the player id in the region
        cout << "the region is belong Player " << temp_number << ", the population minus one will be turn to Player "
             << temp_number << endl;

        (*vectorListOfPlayerPointer)[temp_number - 1].setpopulation((*nr_vPtr)[regionid].getregion_population() - 1);
        (*vectorListOfPlayerPointer)[temp_number - 1].setNumberOfOccupiedRegion((*vectorListOfPlayerPointer)[temp_number - 1].getNumberOfOccupiedRegion() - 1);
    }
}

void Player::redeploymentVeiw(ListofPlayer *lp, vector<NodeRegion> *nr_vPtr) {
    for (int i = 0; i < vnodeRegion.size(); ++i) {
     if(lp->getidPlayer()==(*nr_vPtr)[i].getid_player()){
         int PlayerId=(*nr_vPtr)[i].getid_player();
         int regionPopulation=(*nr_vPtr)[i].getregion_population();
         string regionStatus=(*nr_vPtr)[i].getregion_status();
         cout<<"The region "<<i+1<<" is "<<regionStatus<<" has "<<regionPopulation<<" population."<<endl;
     }


    }
}

void Player::pickupAfterDecline(ListofPlayer *listofplayer, string race, string specialpower, int population) {
    listofplayer->setspecialpower(specialpower);
    listofplayer->setrace(race);
    listofplayer->setpopulation(population);
    listofplayer->setdecline_lock(1);

}

void Player::cleanUpsortbyvplayercoin() {
    sortbyvplayercoin.clear();
    sortbyvplayercoin.shrink_to_fit();
}