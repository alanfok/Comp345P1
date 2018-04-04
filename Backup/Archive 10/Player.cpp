//
// Created by fok poon kai on 2018-02-03.
//

#include "Player.h"

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void Player::conquers(int region, int IdOfplayer ,int invade_region,
                      int player_population
) {

        occupied(region, IdOfplayer, invade_region);
         int temp = player_population;
        vplayer[IdOfplayer-1].setpopulation(vplayer[IdOfplayer-1].getpopulation() -temp);
        vnodeRegion[region].setregion_population(temp);
        vnodeRegion[region].setid_player(IdOfplayer);


}

int Player::Score(){
    return  tokens.victorycoin;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

//////////// new add  ////////// please test//////////
void Player::withdraw(int idplayer, int region , int number_pop_withdraw) {
    region-=1;
   if(maploader.maps.pt[region][region]== idplayer){
       if(number_pop_withdraw< vnodeRegion[region].getregion_population()){
           int n = vnodeRegion[region].getregion_population()-number_pop_withdraw;
           vplayer[idplayer-1].setpopulation(vplayer[idplayer-1].getpopulation()+number_pop_withdraw);
           vnodeRegion[region].setregion_population(n);
       }else if(number_pop_withdraw== vnodeRegion[region].getregion_population()){
           vplayer[idplayer-1].setpopulation(vplayer[idplayer-1].getpopulation()+number_pop_withdraw);
           vnodeRegion[region].setregion_population(0);
           vnodeRegion[region].setid_player(0);
           vnodeRegion[region].setplayer_specialpower("");
           vnodeRegion[region].setplayer_race("");
       }else if (number_pop_withdraw> vnodeRegion[region].getregion_population()){
           cout<<"can't withdraw more than the region's population have"<<endl;

       }

   };



}
void Player::del_pointer() {


    tokens.point_del();
}

void Player::show_information(vector <listOfPlayer> mp)
{
    for(int x = 0; x < mp.size() ; x++)
    {
        //cout << mp[x].getidPlayer() << mp[x].getpopulation() << endl;
        cout <<"Player "<< mp[x].idPlayer <<" victory coin "<< mp[x].victoryCoins
             << " population "<< mp[x].population<< " race "<< mp[x].race << endl;
    }
}
void Player::show_information_of_region()
{
    for(int x = 0; x < vplayer.size() ; x++)
    {
        for(int y = 0; y < maploader.nbline ; y++)
        {
            if(vnodeRegion[y].getid_player()==(x+1))
            {
                //cout << x << endl;
                cout <<"The Player "<<x+1<<" has "<<vnodeRegion[y].getregion_num()
                     <<" status "
                     <<vnodeRegion[y].getregion_status()<<" population "
                     <<vnodeRegion[y].getregion_population()<<endl;
            }
        }
    }
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

    listOfPlayer listOfPlayer(i + 1, vic,p,
                         specialPower,
                          race, decline);

    vplayer.push_back(listOfPlayer);//push into veco


    }


//need fix the map status and player

void Player::collecttoken(int playid) {
    for (int i = 0; i < maploader.nbline; ++i) {
       if((maploader.maps.pt[i][i])==playid)
       {
                vplayer[playid-1].setvictoryCoins(vplayer[playid-1].getvictoryCoins()+1);
        }
       if(vnodeRegion[i].getregion_status().compare("_____farm__")==0&& vplayer[playid-1].getrace().compare("Human")==0){
           vplayer[playid-1].setvictoryCoins(vplayer[playid-1].getvictoryCoins()+1);
       }
        if((maploader.maps.pt[i][i])==playid&&vplayer[playid-1].getrace().compare("Orcs")==0)
        {
            vplayer[playid-1].setvictoryCoins(vplayer[playid-1].getvictoryCoins()+1);
        }




}

}


void Player::token_sort() {    // sorting ny players coin
    for (int i = 300; i >= 0; i--) {
        for(int j=0 ; j<vplayer.size();j++) {
            if(vplayer[j].getvictoryCoins()==i){
                sortbyvplayercoin.push_back(vplayer[j]);
            }
        }
    }
}

void Player::declare_winner(){
    for(int i=300;i>=0;i--){
        for (int i = 300; i >= 0; i--) {
            for(int j=0 ; j<vplayer.size();j++) {
                if(vplayer[j].getvictoryCoins()==i){
                    cout <<vplayer[j].getidPlayer()<<"is winner"<<endl;
                    break;
                }
            }
        }

    }

}



void Player::return_puplation_to_occupied_player(int regionid) {
    if(vnodeRegion[regionid].getid_player()!=0){
      vnodeRegion[regionid].getid_player();
        int temp_pop=vnodeRegion[regionid].getregion_population();
        for (int i = 0; i < vplayer.size(); ++i) {
            if(vplayer[i].getidPlayer()==vnodeRegion[regionid].getid_player()){
                listOfPlayer *lpp=&vplayer[i];
                lpp->setpopulation(lpp->getpopulation()+(temp_pop-1));
                delete lpp;
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

void Player::conquers_v2(int region, int IdOfplayer,int player_population) {
    int temp = player_population;
    vplayer[IdOfplayer-1].setpopulation(vplayer[IdOfplayer-1].getpopulation() -temp);
    vnodeRegion[region].setregion_population(temp);
    vnodeRegion[region].setid_player(IdOfplayer);


}

void Player::withdraw_v2(int region, int Idofplayer, int pop) {
    if(vnodeRegion[region].getid_player()==Idofplayer){
        if(vnodeRegion[region].getregion_population()<pop){//
            cout<<"you can't withdraw more than you have"<<endl;
        }else{//pop withdraw = or less than region has(good)
            int temp = vnodeRegion[region].getregion_population()-pop;
            int temppypop=vplayer[Idofplayer].getpopulation()+pop;
            vnodeRegion[region].setregion_population(temp);
            vplayer[Idofplayer-1].setpopulation(temppypop);
            check_region_is_zero_pop(region);
        }
    } else{//not occupid by the same player
        cout<<"you don't have this region"<<endl;
    }

}

void Player::check_region_is_zero_pop(int region) {
    if (vnodeRegion[region].getregion_population()==0){
        vnodeRegion[region].setid_player(0);//erase the regionid data
        vnodeRegion[region].setplayer_race("");//erase the regionrace data
        vnodeRegion[region].setplayer_specialpower("");  //erase the regionsp data
    }
}

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

void Player::brr(){


    cout<<"▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"<<endl;

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

void Player::AI_redeployment(){
    for (int i = 0; i < vnodeRegion.size(); ++i) {
        if(vnodeRegion[i].getid_player()==vplayer[tempNbIndex].getidPlayer()){
            if(vnodeRegion[i].getregion_population()>1){
                vnodeRegion[i].setregion_population(vnodeRegion[i].getregion_population()-1);
                vplayer[tempNbIndex].setpopulation(vplayer[tempNbIndex].getpopulation()+1);
            }
        }
    }
}







void Player::conquers_v3(int player_population,listOfPlayer *lp, NodeRegion *nr
, int region ,int invade_region) {

    occupied(region, lp->getidPlayer(), invade_region);
    int temp = player_population;
    lp->setpopulation(lp->getpopulation() -temp);
    nr->setregion_population(temp);
    nr->setid_player(lp->getidPlayer());


}


void Player::conquers_v4(listOfPlayer *lp, NodeRegion *nr,int pop){
   int  temp_pop=pop;
    lp->setpopulation(lp->getpopulation()-temp_pop);
    nr->setregion_population(temp_pop);
    nr->setid_player(lp->getidPlayer());
    nr->setplayer_race(lp->getrace());
    nr->setplayer_specialpower(lp->getspecialPower());
}

void Player::test1() {
    cout<<"--------------------------------test1-------------------------------"<<endl;
}
void Player::test2() {
    cout<<"--------------------------------test2-------------------------------"<<endl;
}
void Player::test3() {
    cout<<"--------------------------------test3-------------------------------"<<endl;
}
void Player::test4() {
    cout<<"--------------------------------test4-------------------------------"<<endl;
}


