//
// Created by fok poon kai on 2018-03-31.
//

#include "Strategy.h"
//Aggressive Player  
AggressivePlayer::AggressivePlayer(){}
AggressivePlayer::~AggressivePlayer(){}
void AggressivePlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Aggressive Player"<<endl;
}



void AggressivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);
    total_number_of_region=py.maploader.nbline;
    playerid=lp->getidPlayer();

    playerpop=lp->getpopulation();
    do {

        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {
        Edgeoccupied=false;
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&
                  lp->getspecialPower().compare("Seafaring") != 0){
                Edgeoccupied=false;
            } else{
               py.population_costv2(playerid,randomnumber);
                if(py.cost_of_population>playerpop){
                    Edgeoccupied=false;
                }else {
              //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());
                    py.invade_v2(playerid,randomnumber);
                    py.maploader.losttride[randomnumber] = "_none__";
                    Edgeoccupied=true;
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}






void AggressivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
   // observer.update_conquer();
    cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
   // observer.update_conquer();
    playerid = lp->getidPlayer();
    playerpop = lp->getpopulation();
    phase_observer.update_conquer(*lp_vPtr);
    cout << py.vnodeRegion[randomnumber].getid_player() << "get " << py.vnodeRegion[randomnumber].getregion_status()
         << endl;
    conquer_check = false;


    do {
        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if (py.vnodeRegion[i].getid_player() == playerid) {
                storage.push_back(i);
            }
        }

        for (int j = 0; j < storage.size(); ++j) {
            int temp = storage[j];
            for (int i = 0; i < py.vnodeRegion.size(); ++i) {
                py.population_costv2(playerid, i);

                //return to player who already occupied of this region
                if (py.maploader.maps.pt[temp][i] == 1 &&
                    (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||
                       py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&
                    playerpop >= py.cost_of_population) {


                    if(  (*nr_vPtr)[i].getid_player()!=0){
                        int temp_number=(*nr_vPtr)[i].getid_player();
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[i].getregion_population()-1);
                    }


                    //occupied
                    lp->setpopulation(lp->getpopulation() - py.cost_of_population);
                    (*nr_vPtr)[i].setregion_population(py.cost_of_population);
                    (*nr_vPtr)[i].setid_player(lp->getidPlayer());
                    (*nr_vPtr)[i].setplayer_race(lp->getrace());
                    (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());
                    py.invade_v2(playerid, i);
                    py.maploader.losttride[i] = "_none__";
                    playerpop -= py.cost_of_population;

                } else if (py.maploader.maps.pt[temp][i] == 1 &&
                           (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||
                              py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&
                           playerpop < py.cost_of_population) {
                    cout << "throw the die" << endl;
                    int tempdice = py.getthrowdie();
                    if ((tempdice + playerpop) >= py.cost_of_population) {

                        //conquer package
                        lp->setpopulation(0);
                        (*nr_vPtr)[i].setregion_population(playerpop);
                        (*nr_vPtr)[i].setid_player(lp->getidPlayer());
                        (*nr_vPtr)[i].setplayer_race(lp->getrace());
                        (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());
                        py.invade_v2(playerid, i);
                        py.maploader.losttride[i] = "_none__";
                        playerpop -= py.cost_of_population;


                        //out of the loop
                        conquer_check = true;
                        break;
                    } else {
                        //out of the loop
                        conquer_check = true;
                        break;
                    }
                }

                if (conquer_check == true) {
                    break;
                }
            }

            if (conquer_check == true) {
                break;
            }


        }
    } while (conquer_check == false);

    cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
py.prints();
}


void AggressivePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if((*nr_vPtr)[i].getregion_population()>1){
                (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                lp->setpopulation(lp->getpopulation()+1);
            }
        }
    }
};
void AggressivePlayer::scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else if(lp->getrace().compare("Human")==0&&(*nr_vPtr)[i].getregion_status().compare("_____farm__")){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else{
                lp->setvictoryCoins(lp->getvictoryCoins()+1);
            }
        }
    }
}

//Defense Player 
DefensivePlayer::DefensivePlayer() {} 
DefensivePlayer::~DefensivePlayer() {} 
void DefensivePlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Defensive Player"<<endl;
}


void DefensivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);
    total_number_of_region=py.maploader.nbline;
    playerid=lp->getidPlayer();

    playerpop=lp->getpopulation();
    do {

        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {
            Edgeoccupied=false;
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&
                lp->getspecialPower().compare("Seafaring") != 0){
                Edgeoccupied=false;
            } else{
                py.population_costv2(playerid,randomnumber);
                if(py.cost_of_population>playerpop){
                    Edgeoccupied=false;
                }else {
                    //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());
                    py.invade_v2(playerid,randomnumber);
                    py.maploader.losttride[randomnumber] = "_none__";
                    Edgeoccupied=true;
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}

void DefensivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    playerid = lp->getidPlayer();
    playerpop = lp->getpopulation();
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==playerid){
            (*nr_vPtr)[i].setregion_population(lp->getpopulation());
            lp->setpopulation(0);
        }
    }
}


void DefensivePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if((*nr_vPtr)[i].getregion_population()>1){
                (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                lp->setpopulation(lp->getpopulation()+1);
            }
        }
    }

};
void DefensivePlayer::scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else if(lp->getrace().compare("Human")==0&&(*nr_vPtr)[i].getregion_status().compare("_____farm__")){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else{
                lp->setvictoryCoins(lp->getvictoryCoins()+1);
            }
        }
    }
}
//ModeratePlayer
ModeratePlayer::ModeratePlayer() {}
ModeratePlayer::~ModeratePlayer() {}
void ModeratePlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Moderate Player"<<endl;
    cout<<lp->getidPlayer()<<endl;
//do something};
}
void ModeratePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);
    total_number_of_region=py.maploader.nbline;
    playerid=lp->getidPlayer();

    playerpop=lp->getpopulation();
    do {

        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {
            Edgeoccupied=false;
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&
                lp->getspecialPower().compare("Seafaring") != 0){
                Edgeoccupied=false;
            } else{
                py.population_costv2(playerid,randomnumber);
                if(py.cost_of_population>playerpop){
                    Edgeoccupied=false;
                }else {
                    //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());
                    py.invade_v2(playerid,randomnumber);
                    py.maploader.losttride[randomnumber] = "_none__";
                    Edgeoccupied=true;
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}

void ModeratePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    //decline
    if(lp->getDecline()==false) {
        cout << "We will be decline" << endl;
        lp->setDecline(true);
    }else{
        cout<<"------------------------you already decline once already.------------------------"<<endl;





    }

}
void ModeratePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if((*nr_vPtr)[i].getregion_population()>1){
                (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
             //   lp->setpopulation(lp->getpopulation()+1);
            }
        }
    }
};
void ModeratePlayer::scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else if(lp->getrace().compare("Human")==0&&(*nr_vPtr)[i].getregion_status().compare("_____farm__")){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else{
                lp->setvictoryCoins(lp->getvictoryCoins()+1);
            }
        }
    }
}
////humanPlayer
//HumanPlayer::HumanPlayer() {}
//HumanPlayer::~HumanPlayer() {}
//void HumanPlayer::pickupRaceNSp(listOfPlayer lp,Player py){
//    cout<<"you pick up the Human Player"<<endl;
//    cout<<lp.getidPlayer()<<endl;
//}
//void HumanPlayer::firstEdge(listOfPlayer lp,Player py){}
//
//void HumanPlayer::conquers(listOfPlayer lp,Player py) {
//    //do something
//}
//void HumanPlayer::redeployment(listOfPlayer lp,Player py){};
//void HumanPlayer::scores(listOfPlayer lp,Player py) {
//    //do something
//}




//RandomPlayer
RandomPlayer::RandomPlayer() {} 
RandomPlayer::~RandomPlayer() {} 
void RandomPlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Random Player"<<endl;
    cout<<lp->getidPlayer()<<endl;
}
void RandomPlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);
    total_number_of_region=py.maploader.nbline;
    playerid=lp->getidPlayer();

    playerpop=lp->getpopulation();
    do {

        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {
            Edgeoccupied=false;
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&
                lp->getspecialPower().compare("Seafaring") != 0){
                Edgeoccupied=false;
            } else{
                py.population_costv2(playerid,randomnumber);
                if(py.cost_of_population>playerpop){
                    Edgeoccupied=false;
                }else {
                    //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());
                    py.invade_v2(playerid,randomnumber);
                    py.maploader.losttride[randomnumber] = "_none__";
                    Edgeoccupied=true;
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;



}

void RandomPlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {

    srand(time(NULL));
    randomnumberV2 = (rand()) % 2;
    if(lp->getDecline()==true){
        randomnumberV2=0;
    }


    if(randomnumberV2==0){
        cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
        // observer.update_conquer();
        playerid = lp->getidPlayer();
        playerpop = lp->getpopulation();
        phase_observer.update_conquer(*lp_vPtr);
        cout << py.vnodeRegion[randomnumber].getid_player() << "get " << py.vnodeRegion[randomnumber].getregion_status()
             << endl;
        conquer_check = false;


        do {
            for (int i = 0; i < py.vnodeRegion.size(); ++i) {
                if (py.vnodeRegion[i].getid_player() == playerid) {
                    storage.push_back(i);
                }
            }

            for (int j = 0; j < storage.size(); ++j) {
                int temp = storage[j];
                for (int i = 0; i < py.vnodeRegion.size(); ++i) {
                    py.population_costv2(playerid, i);

                    //return to player who already occupied of this region
                    if (py.maploader.maps.pt[temp][i] == 1 &&
                        (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||
                           py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&
                        playerpop >= py.cost_of_population) {


                        if(  (*nr_vPtr)[i].getid_player()!=0){
                            int temp_number=(*nr_vPtr)[i].getid_player();
                            (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[i].getregion_population()-1);
                        }


                        //occupied
                        lp->setpopulation(lp->getpopulation() - py.cost_of_population);
                        (*nr_vPtr)[i].setregion_population(py.cost_of_population);
                        (*nr_vPtr)[i].setid_player(lp->getidPlayer());
                        (*nr_vPtr)[i].setplayer_race(lp->getrace());
                        (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());
                        py.invade_v2(playerid, i);
                        py.maploader.losttride[i] = "_none__";
                        playerpop -= py.cost_of_population;

                    } else if (py.maploader.maps.pt[temp][i] == 1 &&
                               (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||
                                  py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&
                               playerpop < py.cost_of_population) {
                        cout << "throw the die" << endl;
                        int tempdice = py.getthrowdie();
                        if ((tempdice + playerpop) >= py.cost_of_population) {

                            //conquer package
                            lp->setpopulation(0);
                            (*nr_vPtr)[i].setregion_population(playerpop);
                            (*nr_vPtr)[i].setid_player(lp->getidPlayer());
                            (*nr_vPtr)[i].setplayer_race(lp->getrace());
                            (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());
                            py.invade_v2(playerid, i);
                            py.maploader.losttride[i] = "_none__";
                            playerpop -= py.cost_of_population;


                            //out of the loop
                            conquer_check = true;
                            break;
                        } else {
                            //out of the loop
                            conquer_check = true;
                            break;
                        }
                    }

                    if (conquer_check == true) {
                        break;
                    }
                }

                if (conquer_check == true) {
                    break;
                }


            }
        } while (conquer_check == false);

        cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
        py.prints();






    }else if(randomnumberV2==1){

        cout<<"We will be decline"<<endl;
        lp->setDecline(true);


    }


    //do something
}
void RandomPlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    if(randomnumberV2==0){

        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
                if((*nr_vPtr)[i].getregion_population()>1){
                    (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                    lp->setpopulation(lp->getpopulation()+1);
                }
            }
        }




    }else if(randomnumberV2==1){


        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
                if((*nr_vPtr)[i].getregion_population()>1){
                    (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                    //   lp->setpopulation(lp->getpopulation()+1);
                }
            }
        }






    }








};
void RandomPlayer::scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {


    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else if(lp->getrace().compare("Human")==0&&(*nr_vPtr)[i].getregion_status().compare("_____farm__")){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
            }else{
                lp->setvictoryCoins(lp->getvictoryCoins()+1);
            }
        }
    }


    //do something
}