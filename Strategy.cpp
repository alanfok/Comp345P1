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
void AggressivePlayer::pickupRaceNSp(listOfPlayer *lp){
    cout<<"you pick up the Aggressive Player\n"
            "for the people who select the aggressive player,it will focus to occupid the region until"
            "the end of the game."<<endl;
    cout<<"Player "<<lp->getidPlayer()<<" choose to be an agressive Player"<<endl;
    lp->setStrategyBehaviour(1);//locked strategy in Player object
}


/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    py.prints();
    py.brr();
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<" population(token)"<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);// attach the player Object to Observer
    totalNumberOfRegion=py.maploader.nbline;// get how many region
    playerID=lp->getidPlayer();//get Player ID
    playerPopulation=lp->getpopulation();//get Player population
    do {//go to do loop to make sure the first region is from the edge of the map
        cout<<"please Enter the first region u want to occupy"<<endl;
        cin>>toWhichRegion;
        toWhichRegion-=1;

        if (py.maploader.adjact[toWhichRegion].compare("y") != 0) {//←if the region is not an edge region
            Edgeoccupied=false;//no need to print out becuz it is a AI playing
            cout<<"The first entyr has to be from the edge."<<endl;
        }else{
            if (py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") == 0 && //←if the region is a water region
                lp->getspecialPower().compare("Seafaring") != 0){//←and the player special power is no Seafaring
                Edgeoccupied=false;
                cout<<"The region is a water and you don't have a Seafaring power"<<endl;

            } else{//if all conditions match
                py.population_costv2(playerID,toWhichRegion);//calculation how many region need to occupy that region
                cout<<"the region cost you "<<py.cost_of_population<<" populations"<<endl;
                if(py.cost_of_population>playerPopulation){//if the population cost more that player population
                    Edgeoccupied=false;
                    cout<<"The region costs more population than you have"<<endl;
                }else {
                    //return the previous user
                    py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
                    //↑↑↑ find out the previous region owner and return the region population -1 to previous region owne
                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                    py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
                    py.invade_v2(playerID,toWhichRegion);//←set the matrix map to Player ID
                    py.maploader.losttride[toWhichRegion] = "_none__";//←set the lost tride to none after ocuppied the region
                    Edgeoccupied=true;//get out the do-while loop
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<toWhichRegion+1<<"------------------------"<<endl;
    py.prints();//print out the map
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;

}





/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    // observer.update_conquer();
    cout << "the Player " << lp->getidPlayer() << " has " << lp->getpopulation() <<" population.\n"
            "As Player choose the Aggressive Behavier , you only can occpied the region"<< endl;
    // observer.update_conquer();
    py.prints();
    playerID = lp->getidPlayer();//get Player ID
    playerPopulation = lp->getpopulation();//get Player population
    phase_observer.update_conquer(*lp_vPtr);//calling the Observer to update the information
    cout << py.vnodeRegion[toWhichRegion].getid_player() << "get " << py.vnodeRegion[toWhichRegion].getregion_status()
         << endl;
    conquer_check = false;//get conquer_check to false to do-while loop purpose

    do {
        cout<<"From which region"<<endl;
        cin>>fromWhichRegion;
        fromWhichRegion-=1;
        cout<<"To which region"<<endl;
        cin>>toWhichRegion;
        toWhichRegion-=1;
        py.population_costv2(playerID,toWhichRegion);

        if(py.maploader.maps.pt[fromWhichRegion][toWhichRegion]==0){
            cout<<"they are not linking together"<<endl;
        }else if((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") == 0 &&
                  py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") != 0)){
            cout<<"The region costs more population than you have"<<endl;
        }
        else if (py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1 &&
                 (((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||
                    py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0))) &&
                 playerPopulation >= py.cost_of_population) {

            //↓↓↓return to player who already occupied of this region↓↓↓
            py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
            //occupied
            lp->setpopulation(lp->getpopulation() - py.cost_of_population);//←reset player object population (player origional population - population that player spend)
            py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
            py.invade_v2(playerID, toWhichRegion);//←set the matrix map to Player ID
            py.maploader.losttride[toWhichRegion] = "_none__";//←set the lost tride to none after ocuppied the region
            playerPopulation -= py.cost_of_population;//←the player  population minus player spent population on the region

        }
        else if (py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1 &&
                 (((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||//←if the region is not a water region
                    py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0))) &&//←or the player special power  Seafaring
                 playerPopulation < py.cost_of_population) {//the player population is smaller than the region costs
            cout << "throw the die" << endl;
            int tempdice = py.getthrowdie();//the dice number which calling the dice class
            cout<< "The dice number is " <<tempdice<<" and the total is "<<tempdice + playerPopulation<<endl;

            if ((tempdice + playerPopulation) >= py.cost_of_population) {
                cout<<"The total is more than the region costes, so you can occupy the region"<<endl;
                //return the previous user
                py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
                py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
                py.invade_v2(playerID, toWhichRegion);
                lp->setpopulation(0);//set the Player object popluation to 0
                py.maploader.losttride[toWhichRegion] = "_none__";//←set the matrix map to Player ID
                playerPopulation -= py.cost_of_population;//←set the lost tride to none after ocuppied the region
                conquer_check = true;
            } else {
                cout<<"The total is less than the region costes, so you cannot occupy the region"<<endl;
                conquer_check = true;
            }
        }

    } while (conquer_check == false);

    cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
    py.prints();
}


/*We leave 1 population on the region and take all remaining to Player hands)
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void AggressivePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"Because Player selected the Aggresssive behavior, it will stay 1 popluation(token) on the re"<<endl;
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
void DefensivePlayer::pickupRaceNSp(listOfPlayer *lp){
    cout<<"you pick up the Defensive Player\n"
            "For the people who select the defensive player,it will focus to occupid the region until"
            "the end of the game."<<endl;
    cout<<"Player "<<lp->getidPlayer()<<" choose to be an defensive Player"<<endl;
    lp->setStrategyBehaviour(2);//locked strategy in Player object
}

/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::firstEdge(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    py.prints();
    py.brr();
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<" population(token)"<<endl;
    observer.attach(py.vplayer[py.tempNbIndex]);// attach the player Object to Observer
    totalNumberOfRegion=py.maploader.nbline;// get how many region
    playerID=lp->getidPlayer();//get Player ID
    playerPopulation=lp->getpopulation();//get Player population
    do {//go to do loop to make sure the first region is from the edge of the map
        cout<<"please Enter the first region u want to occupy"<<endl;
        cin>>toWhichRegion;
        toWhichRegion-=1;

        if (py.maploader.adjact[toWhichRegion].compare("y") != 0) {//←if the region is not an edge region
            Edgeoccupied=false;//no need to print out becuz it is a AI playing
            cout<<"The first entyr has to be from the edge."<<endl;
        }else{
            if (py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") == 0 && //←if the region is a water region
                lp->getspecialPower().compare("Seafaring") != 0){//←and the player special power is no Seafaring
                Edgeoccupied=false;
                cout<<"The region is a water and you don't have a Seafaring power"<<endl;

            } else{//if all conditions match
                py.population_costv2(playerID,toWhichRegion);//calculation how many region need to occupy that region
                cout<<"the region cost you "<<py.cost_of_population<<" populations"<<endl;
                if(py.cost_of_population>playerPopulation){//if the population cost more that player population
                    Edgeoccupied=false;
                    cout<<"The region costs more population than you have"<<endl;
                }else {
                    //return the previous user
                    py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
                    //↑↑↑ find out the previous region owner and return the region population -1 to previous region owne
                    lp->setpopulation(lp->getpopulation()-py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                    py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
                    py.invade_v2(playerID,toWhichRegion);//←set the matrix map to Player ID
                    py.maploader.losttride[toWhichRegion] = "_none__";//←set the lost tride to none after ocuppied the region
                    Edgeoccupied=true;//get out the do-while loop
                }
            }
        }
    }while (Edgeoccupied==false);
    cout<<"------------------------The player selected "<<toWhichRegion+1<<"------------------------"<<endl;
    py.prints();//print out the map
    cout<<"Update-->the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<endl;
    firstLock=1;//mu
}


/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {
    cout << "the Player " << lp->getidPlayer() << " has " << lp->getpopulation() <<" population.\n"
            "As Player choose the Defensive Behavier , you only can occpily one region"<< endl;
cout<<"test "<<firstLock<<endl;
    py.prints();
    playerID = lp->getidPlayer();//get Player ID
    playerPopulation = lp->getpopulation();//get Player population
    phase_observer.update_conquer(*lp_vPtr);//calling the Observer to update the information
    cout << py.vnodeRegion[toWhichRegion].getid_player() << "get " << py.vnodeRegion[toWhichRegion].getregion_status()
         << endl;
    conquer_check = false;//get conquer_check to false to do-while loop purpose
if (firstLock==1){
    firstLock=0;
}
    else{
        do {
            cout<<"From which region"<<endl;
            cin>>fromWhichRegion;
            fromWhichRegion-=1;
            cout<<"To which region"<<endl;
            cin>>toWhichRegion;
            toWhichRegion-=1;
            py.population_costv2(playerID,toWhichRegion);

            if(py.maploader.maps.pt[fromWhichRegion][toWhichRegion]==0){
                cout<<"they are not linking together"<<endl;
            }else if((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") == 0 &&
                      py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") != 0)){
                cout<<"The region costs more population than you have"<<endl;
            }
            else if (py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1 &&
                     (((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||
                        py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0))) &&
                     playerPopulation >= py.cost_of_population) {

                //↓↓↓return to player who already occupied of this region↓↓↓
                py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
                //occupied
                lp->setpopulation(lp->getpopulation() - py.cost_of_population);//←reset player object population (player origional population - population that player spend)
                py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
                py.invade_v2(playerID, toWhichRegion);//←set the matrix map to Player ID
                py.maploader.losttride[toWhichRegion] = "_none__";//←set the lost tride to none after ocuppied the region
                playerPopulation -= py.cost_of_population;//←the player  population minus player spent population on the region
                conquer_check= true;

            }
            else if (py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1 &&
                     (((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||//←if the region is not a water region
                        py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0))) &&//←or the player special power  Seafaring
                     playerPopulation < py.cost_of_population) {//the player population is smaller than the region costs
                cout << "throw the die" << endl;
                int tempdice = py.getthrowdie();//the dice number which calling the dice class
                cout<< "The dice number is " <<tempdice<<" and the total is "<<tempdice + playerPopulation<<endl;

                if ((tempdice + playerPopulation) >= py.cost_of_population) {
                    cout<<"The total is more than the region costes, so you can occupy the region"<<endl;
                    //return the previous user
                    py.returnToPreviousPlayer(nr_vPtr,lp_vPtr,toWhichRegion);//in player class(Return to puopluation to ex-ocuppied player)
                    py.conquers_v4(lp,nr_vPtr,py.cost_of_population,toWhichRegion);//in player class
                    py.invade_v2(playerID, toWhichRegion);
                    lp->setpopulation(0);//set the Player object popluation to 0
                    py.maploader.losttride[toWhichRegion] = "_none__";//←set the matrix map to Player ID
                    playerPopulation -= py.cost_of_population;//←set the lost tride to none after ocuppied the region
                    conquer_check = true;
                } else {
                    cout<<"The total is less than the region costes, so you cannot occupy the region"<<endl;
                    conquer_check = true;
                }
            }

            cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
            py.prints();
        } while (conquer_check == false);

}
}


/*We leave 1 population on the region and take all remaining to Player hands)
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){
    cout<<"because you choose the Defensive, you can redeploy the population to defense your region"<<endl;


    redeployment_check= false;
    do{
        cout<<"Do you want to redeploymen\nPress 1: Yes \nPress 2: NO"<<endl;
        cin>>input;
        if(input==2){
            redeployment_check=true;
        }else if(input==1){
        py.redeploymentVeiw(lp,nr_vPtr);
        cout<<"Which region you want to withdraw"<<endl;
        cin>>fromWhichRegion;
            fromWhichRegion-=1;
        if(lp->getidPlayer()==(*nr_vPtr)[fromWhichRegion].getid_player()){
            regionPopulation=(*nr_vPtr)[fromWhichRegion].getregion_population();
            cout<<"How many population you want to withdraw?\n"
                    "(if you take all of the population from region, you will loose the region)"<<endl;
            cin>>redeploymentPopulation;
            if(redeploymentPopulation>regionPopulation){
                cout<<"you cannot take more than Region has"<<endl;
            }else{
                (*nr_vPtr)[fromWhichRegion].setregion_population(regionPopulation-redeploymentPopulation);
                cout<<"Which region you want to put the population to"<<endl;
                cin>>toWhichRegion;
                toWhichRegion-=1;
                regionPopulation=(*nr_vPtr)[toWhichRegion].getregion_population();
                (*nr_vPtr)[toWhichRegion].setregion_population(regionPopulation+redeploymentPopulation);
            }
        }
        }





    }while(redeployment_check== false);

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
void ModeratePlayer::pickupRaceNSp(listOfPlayer *lp){
    cout<<"you pick up the ModeratePlayer Player\n"
            "For the people who select the moderatePlayer,it will focus to occupid the region until"
            "the end of the game."<<endl;
    cout<<"Player "<<lp->getidPlayer()<<" choose to be an moderatePlaye Player"<<endl;
    lp->setStrategyBehaviour(3);//locked strategy in Player object
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




//RandomPlayer
RandomPlayer::RandomPlayer() {} 
RandomPlayer::~RandomPlayer() {} 
void RandomPlayer::pickupRaceNSp(listOfPlayer *lp){
    cout<<"you pick up the Random Player\n"
            "For the people who select the random player,it will focus to occupid the region until"
            "the end of the game."<<endl;
    cout<<"you pick up the Random Player"<<endl;
    cout<<"Player "<<lp->getidPlayer()<<" choose to be an random Player"<<endl;
    lp->setStrategyBehaviour(4);//locked strategy in Player object
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