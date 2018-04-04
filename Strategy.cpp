//
// Created by fok poon kai on 2018-03-31.
//

#include "Strategy.h"
//Strategy pattern  implement


//Aggressive Player  
AggressivePlayer::AggressivePlayer(){}
AggressivePlayer::~AggressivePlayer(){}

/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion>* nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Aggressive Player"<<endl;
}


/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);// attach the player Object to Observer
    total_number_of_region=py.maploader.nbline;// get how many region
    playerid=lp->getidPlayer();//get Player ID
    playerpop=lp->getpopulation();//get Player population
    do {//go to do loop to make sure the first region is from the edge of the map
        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {//←if the region is not an edge region
            Edgeoccupied=false;//no need to print out becuz it is a AI playing
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 && //←if the region is a water region
                lp->getspecialPower().compare("Seafaring") != 0){//←and the player special power is no Seafaring
                Edgeoccupied=false;//no need to print out becuz it is a AI playing
            } else{//if all conditions match
                py.population_costv2(playerid,randomnumber);//calculation how many region need to occupy that region
                if(py.cost_of_population>playerpop){//if the population cost more that player population
                    Edgeoccupied=false;
                }else {
                    //return the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){//if the region  No 0,0=no player
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();//get the player id in the region
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                        //↑↑↑ find out the previous region owner and return the region population -1 to previous region owner
                    }
                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);//←reset the regional object to new population
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());//←reset the regional object to new Player ID
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());//←reset the regional object to new Player population
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power
                    py.invade_v2(playerid,randomnumber);//←set the matrix map to Player ID
                    py.maploader.losttride[randomnumber] = "_none__";//←set the lost tride to none after ocuppied the region
                    Edgeoccupied=true;//get out the do-while loop
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();//print out the map
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}





/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    // observer.update_conquer();
    cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
    // observer.update_conquer();
    playerid = lp->getidPlayer();//get Player ID
    playerpop = lp->getpopulation();//get Player population
    phase_observer.update_conquer(*lp_vPtr);//calling the Observer to update the information
    cout << py.vnodeRegion[randomnumber].getid_player() << "get " << py.vnodeRegion[randomnumber].getregion_status()
         << endl;
    conquer_check = false;//get conquer_check to false to do-while loop purpose


    do {
        //↓↓↓ the store the region Object vector index number for future occupy purpose↓↓↓
        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if (py.vnodeRegion[i].getid_player() == playerid) {
                storage.push_back(i);//store Object vector index in the storage vector if the player owns this region
            }
        }
        //↓↓↓ Occupied the region by using for loop↓↓↓
        for (int j = 0; j < storage.size(); ++j) {
            int temp = storage[j];//get the region then player already occupied by reading in "storage" vecotor
            //↓↓↓by using loop the check the region player ID mactch the player id↓↓↓
            for (int i = 0; i < py.vnodeRegion.size(); ++i) {
                py.population_costv2(playerid, i);

              /*check the matrix [x][y],x=region that player already occupid, y= region wanna occupy, is 1 which
                mean is linking ,and (the y is not water region or player has seafaring), and player population is
                equal or bigger the y cost
                ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
                */
                if (py.maploader.maps.pt[temp][i] == 1 &&
                    (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||
                       py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&
                    playerpop >= py.cost_of_population) {

                        //↓↓↓return to player who already occupied of this region↓↓↓
                    if(  (*nr_vPtr)[i].getid_player()!=0){//if the region  No 0,0=no player
                        int temp_number=(*nr_vPtr)[i].getid_player();//get the player id in the region
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[i].getregion_population()-1);
                        //↑↑↑ find out the previous region owner and return the region population -1 to previous region owner
                    }


                    //occupied
                    lp->setpopulation(lp->getpopulation() - py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                    (*nr_vPtr)[i].setregion_population(py.cost_of_population);//←reset the regional object to new population
                    (*nr_vPtr)[i].setid_player(lp->getidPlayer());//←reset the regional object to new Player ID
                    (*nr_vPtr)[i].setplayer_race(lp->getrace());//←reset the regional object to new Player population
                    (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power
                    py.invade_v2(playerid, i);//←set the matrix map to Player ID
                    py.maploader.losttride[i] = "_none__";//←set the lost tride to none after ocuppied the region
                    playerpop -= py.cost_of_population;//←the player  population minus player spent population on the region

                }
                    /*check the matrix [x][y],x=region that player already occupid, y= region wanna occupy, is 1 which
                   mean is linking ,and (the y is not water region or player has seafaring), and player population is
                   smaller than the y cost
                   ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
                   */
                else if (py.maploader.maps.pt[temp][i] == 1 &&
                           (((py.vnodeRegion[i].getregion_status().compare("____water__") != 0 ||//←if the region is not a water region
                              py.vplayer[i].getspecialPower().compare("Seafaring") == 0))) &&//←or the player special power  Seafaring
                           playerpop < py.cost_of_population) {//the player population is smaller than the region costs
                    cout << "throw the die" << endl;
                    int tempdice = py.getthrowdie();//the dice number which calling the dice class
                    cout<< "The dice number is " <<tempdice<<" and the total is "<<tempdice + playerpop<<endl;

                    if ((tempdice + playerpop) >= py.cost_of_population) {
                        //return the previous user
                        if(  (*nr_vPtr)[randomnumber].getid_player()!=0){//if the region  No 0,0=no player
                            int temp_number=(*nr_vPtr)[randomnumber].getid_player();//get the player id in the region
                            (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                            //↑↑↑ find out the previous region owner and return the region population -1 to previous region owner
                        }
                        //conquer package
                        lp->setpopulation(0);//set the Player object popluation to 0
                        (*nr_vPtr)[i].setregion_population(playerpop);//←reset the regional object to new population which player already have
                        (*nr_vPtr)[i].setid_player(lp->getidPlayer());//←reset the regional object to new Player ID
                        (*nr_vPtr)[i].setplayer_race(lp->getrace());//←reset the regional object to new Player population
                        (*nr_vPtr)[i].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power
                        py.invade_v2(playerid, i);
                        py.maploader.losttride[i] = "_none__";//←set the matrix map to Player ID
                        playerpop -= py.cost_of_population;//←set the lost tride to none after ocuppied the region


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


/*We leave 1 population on the region and take all remaining to Player hands)
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
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

/*
 Collect the victory coin
 */
void AggressivePlayer::scores(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            //↓↓if the player race is Orcs
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
                //↓↓if the player race is human and region is farm
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



/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::pickupRaceNSp(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"you pick up the Defensive Player"<<endl;
}

/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);// attach the player Object to Observer
    total_number_of_region=py.maploader.nbline;// get how many region
    playerid=lp->getidPlayer();//get Player ID

    playerpop=lp->getpopulation();//get Player population
    do {//go to do loop to make sure the first region is from the edge of the map

        srand(time(NULL));
        randomnumber = (rand()) % total_number_of_region;
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {//←if the region is not an edge region
            Edgeoccupied=false;//no need to print out becuz it is a AI playing
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&//←if the region is a water region
                lp->getspecialPower().compare("Seafaring") != 0){//←and the player special power is no Seafaring
                Edgeoccupied=false;//no need to print out becuz it is a AI playing
            } else{//if all conditions match
                py.population_costv2(playerid,randomnumber);//calculation how many region need to occupy that region
                if(py.cost_of_population>playerpop){//if the population cost more that player population
                    Edgeoccupied=false;
                }else {
                    //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){//if the region  No 0,0=no player
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();//get the player id in the region
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                        //↑↑↑ find out the previous region owner and return the region population -1 to previous region owner
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);//←reset the regional object to new population
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());//←reset the regional object to new Player ID
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());//←reset the regional object to new Player population
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power
                    py.invade_v2(playerid,randomnumber);//←set the matrix map to Player ID
                    py.maploader.losttride[randomnumber] = "_none__";//←set the lost tride to none after ocuppied the region
                    Edgeoccupied=true;//get out the do-while loop
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}


/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    playerid = lp->getidPlayer();//get Player ID
    playerpop = lp->getpopulation();//get Player population
    /*we put all population in the same region
     * */
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==playerid){
            (*nr_vPtr)[i].setregion_population(lp->getpopulation());
            lp->setpopulation(0);
        }
    }
}


/*We leave 1 population on the region and take all remaining to Player hands)
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
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
            //↓↓if the player race is Orcs
            if(lp->getrace().compare("Orcs")==0){
                lp->setvictoryCoins(lp->getvictoryCoins()+2);
                //↓↓if the player race is human and region is farm
            }else if(lp->getrace().compare("Human")==0&&(*nr_vPtr)[i].getregion_status().compare("_____farm__")==0){
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
/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
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
        randomnumber = (rand()) % total_number_of_region;//generate random number
        if (py.maploader.adjact[randomnumber].compare("y") != 0) {//←if the region is not an edge region
            Edgeoccupied=false;//no need to print out becuz it is a AI playing
        }else{
            if (py.vnodeRegion[randomnumber].getregion_status().compare("____water__") == 0 &&//←if the region is a water region
                lp->getspecialPower().compare("Seafaring") != 0){//←and the player special power is no Seafaring
                Edgeoccupied=false;//no need to print out becuz it is a AI playing
            } else{//if all conditions match
                py.population_costv2(playerid,randomnumber);//calculation how many region need to occupy that region
                if(py.cost_of_population>playerpop){//if the population cost more that player population
                    Edgeoccupied=false;
                }else {
                    //reutrn the previous user
                    if(  (*nr_vPtr)[randomnumber].getid_player()!=0){//if the region  No 0,0=no player
                        int temp_number=(*nr_vPtr)[randomnumber].getid_player();//get the player id in the region
                        (*lp_vPtr)[temp_number-1].setpopulation((*nr_vPtr)[randomnumber].getregion_population()-1);
                        //↑↑↑ find out the previous region owner and return the region population -1 to previous region owner
                    }

                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);//←reset player object population
                    (*nr_vPtr)[randomnumber].setregion_population(py.cost_of_population);//←reset the region object population
                    (*nr_vPtr)[randomnumber].setid_player(lp->getidPlayer());//←reset the region object ID
                    (*nr_vPtr)[randomnumber].setplayer_race(lp->getrace());//←reset the region object race
                    (*nr_vPtr)[randomnumber].setplayer_specialpower(lp->getspecialPower());//←reset the regional object to new Player special power
                    py.invade_v2(playerid,randomnumber);//←set the matrix map to Player ID
                    py.maploader.losttride[randomnumber] = "_none__";//←set the lost tride to none after ocuppied the region
                    Edgeoccupied=true;//get out the do-while loop
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<randomnumber+1<<"------------------------"<<endl;
    py.prints();
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
}

/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void ModeratePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    //if(player no require decline in percious round and the player no even delcine before)
    if(lp->getDecline()==false&& lp->getdecline_lock()==0) {
        cout << "We will be decline" << endl;
        lp->setDecline(true);//set player to decline and ask to pick up the new race next turn.
    }
        // if player already decline before, we will be aggressive player pattern
    else{
        cout<<"------------------------you already decline once already.------------------------"<<endl;
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
                        cout<< "The dice number is " <<tempdice<<" and the total is "<<tempdice + playerpop<<endl;

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

}
void ModeratePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    for (int i = 0; i < py.vnodeRegion.size(); ++i) {
        if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
            if((*nr_vPtr)[i].getregion_population()>1){
                (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                //   lp->setpopulation(lp->getpopulation()+1); leave 1 population on region and erase all remaining population
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
//same with above
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

//becuz of ramdon it will have 50% chance it will decline or follow aggressive occupied method
void RandomPlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {

    srand(time(NULL));
    randomnumberV2 = (rand()) % 2;// randomnumber will be 1 or 0
    if(lp->getDecline()==true){
/* if the player already decline before, we will follow the aggressive player occupied method
 * */
        randomnumberV2=0;
    }

//same with aggessive occiped method, explanation in above
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
        //decline method, same with the moderate class
        cout<<"We will be decline"<<endl;
        lp->setDecline(true);


    }

}
void RandomPlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    if(randomnumberV2==0){//we selected aggressive occupied meth

        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
                if((*nr_vPtr)[i].getregion_population()>1){
                    (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                    lp->setpopulation(lp->getpopulation()+1);
                }
            }
        }




    }else if(randomnumberV2==1){//we selected decline


        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
                if((*nr_vPtr)[i].getregion_population()>1){
                    (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                    //   lp->setpopulation(lp->getpopulation()+1);leave 1 population on region and erase all remaining population
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
