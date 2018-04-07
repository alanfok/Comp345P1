//
// Created by fok poon kai on 2018-04-06.
//

#include "RandomPlayer.h"

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
    py.prints();
    py.brr();
    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<" population(token)"<<endl;

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

//becuz of ramdon it will have 50% chance it will decline or follow aggressive occupied method
void RandomPlayer::conquers(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr) {

    srand(time(NULL));
    randomnumberV2 = (rand()) % 3;// randomnumber will be 1 or 0
    if(lp->getDecline()==true){
/* if the player already decline before, we will follow the aggressive player occupied method
 * */ srand(time(NULL));
        randomnumberV2 = (rand()) % 2;
    }

//same with aggessive occiped method, explanation in above
    if(randomnumberV2==0){
        py.prints();
        py.brr();
        cout<<"------------------------first entry to the map------------------------"<<endl;
        cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<" population(token)"<<endl;

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
    else if(randomnumberV2==1){

        cout << "the Player " << lp->getidPlayer() << " has " << lp->getpopulation() <<" population.\n"
                "As Player choose the Defensive Behavier , you only can occpily one region"<< endl;
        py.prints();
        playerID = lp->getidPlayer();//get Player ID
        playerPopulation = lp->getpopulation();//get Player population

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

    }else if(randomnumberV2==2){
        //decline method, same with the moderate class
        cout<<"We will be decline"<<endl;
        lp->setDecline(true);


    }

}
void RandomPlayer::redeployment(listOfPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<listOfPlayer> *lp_vPtr){

    if(randomnumberV2==0){//we selected aggressive occupied meth

        cout<<"Because Player selected the Aggresssive behavior, it will stay 1 popluation(token) on the re"<<endl;
        for (int i = 0; i < py.vnodeRegion.size(); ++i) {
            if((*nr_vPtr)[i].getid_player()==lp->getidPlayer()){
                if((*nr_vPtr)[i].getregion_population()>1){
                    (*nr_vPtr)[i].setregion_population((*nr_vPtr)[i].getregion_population()-1);
                    lp->setpopulation(lp->getpopulation()+1);
                }
            }
        }


    }else if(randomnumberV2==1){//we selected decline

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