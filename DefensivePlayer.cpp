//
// Created by fok poon kai on 2018-04-06.
//

#include "DefensivePlayer.h"
DefensivePlayer::DefensivePlayer() {} 
DefensivePlayer::~DefensivePlayer() {} 



/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::pickupRaceNSp(ListofPlayer *lp){
    cout<<"you pick up the Defensive Player\n"
            "For the people who select the defensive player,it will focus to occupid the region until"
            "the end of the game."<<endl;
    cout<<"Player "<<lp->getidPlayer()<<" choose to be an defensive Player"<<endl;
    lp->setStrategyBehaviour(2);//locked strategy in Player object
}

/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::firstEdge(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr){
    py.prints();

    cout<<"------------------------first entry to the map------------------------"<<endl;
    cout<<"the Player "<<lp->getidPlayer()<<" and "<< lp->getpopulation()<<" population(token)"<<endl;

    totalNumberOfRegion=py.maploader.nbline;// get how many region
    playerID=lp->getidPlayer();//get Player ID
    playerPopulation=lp->getpopulation();//get Player population
    do {//go to do loop to make sure the first region is from the edge of the map
        cout<<"please Enter the first region u want to occupy"<<endl;
        cin>>toWhichRegion;


        try {
            if(cin.fail()) {
                cin.clear();
                throw toWhichRegion;
                // if the input is not an integer, an error is thrown
                // claudia
            }
            else if (toWhichRegion < 0 || toWhichRegion > totalNumberOfRegion) {
                throw toWhichRegion;
            }
            else{
                Edgeoccupied=true;
            }

        } catch (int toWhichRegion) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "The input is invalid\nPlease enter again" << endl;//catch the unexpect input from user
            cin.clear();
        }// claudia : Added error validatio


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
 //   firstLock=1;//mu
}


/*pass thus (pointer of Player Object, Player class for Player class method, pointer of vector which holding the region
 * Object, pointer of vector which holding the player Object )
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::conquers(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr) {
    cout << "the Player " << lp->getidPlayer() << " has " << lp->getpopulation() <<" population.\n"
            "As Player choose the Defensive Behavier , you only can occpily one region"<< endl;
    lock=0;
    playerID = lp->getidPlayer();//get Player ID
    playerPopulation = lp->getpopulation();//get Player population

    conquer_check = false;//get conquer_check to false to do-while loop purpose

        do {
            veiwer.getPlayerInfoAndShowOccupiedregion(lp->getidPlayer(),py);
            fromregion=false;
            do{
                cout<<"From which region"<<endl;
                cin>>fromWhichRegion;
                try {
                    if(cin.fail()) {
                        cin.clear();
                        throw fromWhichRegion;
                        // if the input is not an integer, an error is thrown
                        // claudia
                    }
                    else if (fromWhichRegion < 0 || fromWhichRegion > totalNumberOfRegion) {
                        throw fromWhichRegion;
                    }
                    else{
                        fromregion=true;
                    }
                } catch (int fromWhichRegion) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "The input is invalid\nPlease enter again" << endl;//catch the unexpect input
                    cin.clear();
                }
            }while(fromregion == false);
            fromWhichRegion-=1;

            toregion = false;
            do{
                cout<<"To which region"<<endl;
                cin>>toWhichRegion;

                try {
                    if(cin.fail()) {
                        cin.clear();
                        throw toWhichRegion;
                        // if the input is not an integer, an error is thrown
                        // claudia
                    }
                    else if (toWhichRegion < 0 || toWhichRegion > totalNumberOfRegion) {
                        throw toWhichRegion;
                    }
                    else{
                        toregion=true;
                    }
                } catch (int fromWhichRegion) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "The input is invalid\nPlease enter again" << endl;
                    cin.clear();
                }// claudia : Added error validation
            }while(toregion == false);
            toWhichRegion-=1;
            py.population_costv2(playerID,toWhichRegion);//calculation the calculation that region cost: in token.cpp
            cout<< "the region cost "<<py.cost_of_population<<endl;
            if(py.maploader.maps.pt[fromWhichRegion][toWhichRegion]==0){
                cout<<"they are not linking together"<<endl;
            }

            else if(lock>=3){//safty lock to avoid infinity loop if no region link
                cout<<"You already try to occupy region 3 times, to avoid infinity loop, you can press 1 to quit the occupy stage?" <<endl;
                cin>>input2;
                if(input2==1){
                    conquer_check=true;
                } else{
                    cout<<"continue"<<endl;
                }

            }
            else if(py.maploader.maps.pt[toWhichRegion][toWhichRegion]==lp->getidPlayer()){
                cout<<"you already occupied that region"<<endl;
            }
            else if((py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") == 0 &&
                      py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") != 0)){
                cout<<"The region costs more population than you have"<<endl;
            }
            else if ((py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1||py.maploader.adjact[toWhichRegion].compare("y") == 0) &&
                     (py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||
                        py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0) &&
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
            else if ((py.maploader.maps.pt[fromWhichRegion][toWhichRegion] == 1||py.maploader.adjact[toWhichRegion].compare("y") == 0) &&
                     (py.vnodeRegion[toWhichRegion].getregion_status().compare("____water__") != 0 ||//←if the region is not a water region
                        py.vplayer[toWhichRegion].getspecialPower().compare("Seafaring") == 0) &&//←or the player special power  Seafaring
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
                    cout<<"The total is less than the region costs, so you cannot occupy the region"<<endl;
                    conquer_check = true;
                }
            }

            cout << "the Player " << lp->getidPlayer() << " and " << lp->getpopulation() << endl;
            py.prints();
            lock++;
        } while (conquer_check == false);

   // }
}


/*We leave 1 population on the region and take all remaining to Player hands)
 *↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ */
void DefensivePlayer::redeployment(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr){
    cout<<"because you choose the Defensive, you can redeploy the population to defense your region"<<endl;


    redeployment_check= false;
    do{
        cout<<"Do you want to redeployment\nPress 1: Yes \nPress 2: NO"<<endl;
        cin>>input;
        try {


            if(cin.fail()) {
                cin.clear();
                throw input;
                // if the input is not an integer, an error is thrown
                // claudia
            }

            else if(input<1||input>2){
                throw input;
            }
            else if(input==2){
                redeployment_check=true;
                cout<<"we move to next step"<<endl;
            }
            else if(input==1){
                veiwer.getPlayerInfoAndShowOccupiedregion(lp->getidPlayer(),py);//view the player and occupied region infor
                cout<<"Which region you want to withdraw"<<endl;
                cin>>fromWhichRegion;
                fromWhichRegion-=1;
                if(lp->getidPlayer()==(*nr_vPtr)[fromWhichRegion].getid_player()){
                    regionPopulation=(*nr_vPtr)[fromWhichRegion].getregion_population();
                    cout<<"How many population you want to withdraw?\n"
                            "(if you take all of the population from region, you will loose the region)"<<endl;
                    cin>>getRedeploymentPopulation;

                    if(getRedeploymentPopulation>regionPopulation){
                        cout<<"you cannot take more than Region has"<<endl;
                    }else{
                        (*nr_vPtr)[fromWhichRegion].setregion_population(regionPopulation-getRedeploymentPopulation);
                        lp->setpopulation(lp->getpopulation()+getRedeploymentPopulation);
                        cout<<"Which region you want to put the population to"<<endl;
                        cin>>toWhichRegion;
                        toWhichRegion-=1;
                        cout<<"How many population you want to put on region?\n" <<endl;
                        cin>>putRedeploymentPopulation;
                        if(putRedeploymentPopulation>lp->getpopulation()){
                            cout<<"you can't put more than you have"<<endl;
                        }
                        regionPopulation=(*nr_vPtr)[toWhichRegion].getregion_population();
                        (*nr_vPtr)[toWhichRegion].setregion_population(regionPopulation+putRedeploymentPopulation);
                        lp->setpopulation(lp->getpopulation()-putRedeploymentPopulation);
                    }
                }
            }
        }catch(int input){
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "The input is invalid\nPlease enter again" << endl;
            cin.clear();
        }catch (...){
            cout<<"the type is not right"<<endl;
        }


    }while(redeployment_check== false);

};
void DefensivePlayer::scores(ListofPlayer *lp,Player py,vector <NodeRegion> *nr_vPtr,vector<ListofPlayer> *lp_vPtr) {
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