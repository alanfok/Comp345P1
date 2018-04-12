//
// Created by fok poon kai on 2018-03-09.
//
//the vectors and node class called in player class
//so every time u call the vector value, u need call player.vplayer
// hava a bugs to occupied
//or player.vnoderegion
//
#include "Interraction.h"


void Interraction ::setplayer(string map, int nbplayer) {

    maps_using = map;//<~~~~change
    player.maploader.setmap(maps_using);//important don't erase
    maploader.setmap(maps_using);//important don't erase
    player.enter_race_sp_to_vector();//important don't erase
    player.set_vnodeRegion_Vector(player.maploader.nbline);
    po=new PhaseObserver();
    so=new StatisticsObserve();
    for (int p = 0; p < nbplayer; p++) {
        playercounter.push_back(0);
        lostRegions.push_back(0);
    }


    br();//print out break line
    player.prints();//print out the map
    br();//print out break line
    for (int i = 0; i < nbplayer; ++i) {
        player.setRace_population(0);
        numberOfPopulation = 0;
        player.vrace_vspecialpower_print();
        cout << "pick race" << endl;
        //cin >> raceSelection;
        // claudia :commented out code
        //claudia
        check=false;// alan u forget to reset
        do {
            cin >> raceSelection;
            try {
                if (cin.fail()) {
                    cin.clear();
                    throw raceSelection;
                    // if the input is not an integer, an error is thrown
                    // claudia
                } else if (raceSelection > 6 || raceSelection < 1) {
                    throw raceSelection;
                } else{
                    check=true;
                }
            }
            catch (int raceSelection) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "The Entry is Invalid, Please try again." << endl;
                // claudia : Fixed Grammar and made it easier to understand
                cin.clear();
            }
        }while(check==false);

        // claudia
        cout << "This race you picking us " << player.getvrace(raceSelection) << " "
             << player.getvspecialpower(raceSelection) << endl;
        victorycoin = 5;//start with 5 victory coin
        /*using the static array to hold the victory coin ,if player pick the
        first race , player doesn't need to pay a victory coin
        if player pick the second , player has to pay one victory coin*/



        for (int j = 1; j < raceSelection; j++) {
            race_coin[j] += 1;//put one coin into array
            victorycoin--;//minus the coin
        }

        victorycoin += race_coin[raceSelection];//victory plus the coin that the array holding
        race_coin[raceSelection] = 0;//reset the index of array that the coin holding =0;
        player.race_population_determind(player.getvrace(raceSelection), player.getvspecialpower(raceSelection));
        //determind how many popualation that race and special power combine
        numberOfPopulation = player.getRace_population();//get the population from player class
        cout << "You have " << numberOfPopulation << " poulation" << endl;

        player.pickup(i, victorycoin, numberOfPopulation, player.getvspecialpower(raceSelection),
                      player.getvrace(raceSelection), false);//function calling,create the player object
        player.tempNbIndex = i;//for strategy purpose
        player.shift(raceSelection);//shift up the race and special power to replace that player toke
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        first_time_edge = true;//
        tempvplayerid = player.vplayer[i].getidPlayer();//temp playid
        tempvplayerpop = player.vplayer[i].getpopulation();//temp player pop
        br();

        player.tempPlayerId=player.vplayer[i].getidPlayer();//for observer purpose
        //strategy
        cout << "Select the player type         \n"
                "Press 1:AggressivePlayer       \n"
                "Press 2:DefensivePlayer        \n"
                "Press 3:ModeratePlaye          \n"
                "Press 4:RandomPlayer           \n"
             << endl;//strategy

        //use try and catch

        player_pointer=&player;
        lp=&player.vplayer[i];
        po=new PhaseObserver();//create object and put it into healp
        so=new StatisticsObserve();;//create object and put it into healp
        player_pointer->attach(po);//attach

        inputCheck=false;
        do {
            cin >> input;
            try {

                if (cin.fail()) {
                    cin.clear();
                    throw raceSelection;
                    // if the input is not an integer, an error is thrown
                    // claudia
                }


                if (input < 0 || input > 4) {
                    throw input;
                }
                else if (input == 1) {
                    player.vplayer[i].setPhase("turn");//set player phase to turn
                    player_pointer->notify(&player.vplayer[i]);//print out
                    aggressivePlayer.pickupRaceNSp(&player.vplayer[i]);
                    br();
                    aggressivePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                               &player.vplayer);//change  <~~make sure the player is entry from edge


                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);

                    player.vplayer[i].setPhase("conquer");
                    player_pointer->notify(&player.vplayer[i]);

                    aggressivePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                              &player.vplayer);//change <~~ occupied
                    //call aggressive conquer class
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);



                    br();
                    player.vplayer[i].setPhase("coin");
                    player_pointer->notify(&player.vplayer[i]);
                    aggressivePlayer.scores(&player.vplayer[i], player, &player.vnodeRegion,
                                            &player.vplayer);
                    //collect token
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    inputCheck=true;
                } else if (input == 2) {
                    player.vplayer[i].setPhase("turn");//set player phase to turn
                    player_pointer->notify(&player.vplayer[i]);//print out
                    defensePlayer.pickupRaceNSp(&player.vplayer[i]);
                    defensePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                            &player.vplayer);//change  <~~make sure the player is entry from edge
//                    defensePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
//                                           &player.vplayer);//change  <~~ occupied
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    br();

                    defensePlayer.redeployment(&player.vplayer[i], player, &player.vnodeRegion,
                                               &player.vplayer);
                    //call redeploymment function in defensePlayer.cpp
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);

                    br();
                    player.vplayer[i].setPhase("coin");
                    player_pointer->notify(&player.vplayer[i]);
                    defensePlayer.scores(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                    //call scores function in defensePlayer.cpp
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    inputCheck=true;
                } else if (input == 3) {

                    player.vplayer[i].setPhase("turn");
                    player_pointer->notify(&player.vplayer[i]);
                    moderatePlayer.pickupRaceNSp(&player.vplayer[i]);
                    moderatePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                             &player.vplayer);//change  <~~make sure the player is entry from edge
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    br();
                    player.vplayer[i].setPhase("conquer");
                    //
                    player_pointer->notify(&player.vplayer[i]);
                    moderatePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                            &player.vplayer);//change   <~~ occupied
                    //call moderate conquer class
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    br();

                    player.vplayer[i].setPhase("coin");
                    player_pointer->notify(&player.vplayer[i]);
                    moderatePlayer.scores(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    inputCheck=true;
                } else if (input == 4) {





                    player.vplayer[i].setPhase("turn");
                    player_pointer->notify(&player.vplayer[i]);
                    randomPlayer.pickupRaceNSp(&player.vplayer[i]);
                    randomPlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                           &player.vplayer);//change  <~~make sure the player is entry from edge

                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    br();


                    player.vplayer[i].setPhase("conquer");
                    player_pointer->notify(&player.vplayer[i]);
                    randomPlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                          &player.vplayer);//change   <~~ occupied
                    //call randomPlayer conquer class
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    br();

                    player.vplayer[i].setPhase("coin");
                    player_pointer->notify(&player.vplayer[i]);
                    randomPlayer.scores(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                    //call scores function in defensePlayer.cpp
                    veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[i].getidPlayer(),player);
                    inputCheck=true;
                }

            } catch (int input) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                cout << "the input is invalid \n"
                        "Enter again:"<< endl;
                cin.clear();

            }
            catch (...){
                cout<<"the type is not right"<<endl;
            }
            player_pointer->detach();
        }while(inputCheck==false);

        cout << "the Player " << player.vplayer[i].getidPlayer() << " and " << player.vplayer[i].getpopulation()
             << endl;

        player.prints();
    }
    veiwer.showAllPlayerInformation(player);
    player_pointer->attachStatic(so);
    player_pointer->notifyStatic(&player.vplayer,maploader.nbline);//so how many percentage that player occupied the map
    //turn 2-10
    for (int j = 2; j <=10 ; ++j) {//2-10 loop


        player.token_sort();
        tempStorage.clear();
        tempStorage.shrink_to_fit();
        player_pointer->attach(po);



        for (int k = 0; k < player.sortbyvplayercoin.size(); ++k) {
            for (int l = 0; l < player.vplayer.size(); ++l) {

                if (player.vplayer[k].getidPlayer() == player.vplayer[l].getidPlayer()) {
                    tempStorage.push_back(player.vplayer[l].getidPlayer());
                }
            }
        }
     // player loop
    for (int indexOftempStorage = 0; indexOftempStorage < tempStorage.size(); ++indexOftempStorage) {
            indexOfPlayerVector=tempStorage[indexOftempStorage];
            indexOfPlayerVector-=1;
         player.vplayer[indexOfPlayerVector].setTurn(j);
        //////check decline ///////////
        if (player.vplayer[indexOfPlayerVector].getDecline() == true &&
            player.vplayer[indexOfPlayerVector].getdecline_lock() == 0) {//for player object who select decline
            player.setRace_population(0);
            numberOfPopulation = 0;
            player.vrace_vspecialpower_print();
            cout << "pick race" << endl;
            cin >> raceSelection;
            cout << "This race you picking us " << player.getvrace(raceSelection) << " "
                 << player.getvspecialpower(raceSelection) << endl;
            for (int i = 1; i < raceSelection; i++) {
                race_coin[i] += 1;
                player.vplayer[indexOfPlayerVector].setvictoryCoins(
                        player.vplayer[indexOfPlayerVector].getvictoryCoins() - 1);
            }
            player.vplayer[indexOfPlayerVector].setvictoryCoins(
                    player.vplayer[indexOfPlayerVector].getvictoryCoins() + race_coin[raceSelection]);
            race_coin[raceSelection] = 0;
            player.race_population_determind(player.getvrace(raceSelection),
                                             player.getvspecialpower(raceSelection));
            numberOfPopulation = player.getRace_population();
            cout << "You have " << numberOfPopulation << " poulation" << endl;
            player.pickupAfterDecline(&player.vplayer[indexOfPlayerVector], player.getvrace(raceSelection),
                                      player.getvspecialpower(raceSelection), numberOfPopulation);
            player.shift(raceSelection);

        }

        //////check decline end///////////


        if (player.vplayer[indexOfPlayerVector].getStrategyBehaviour() == 1) {//Aggressive behaviour
            player.vplayer[indexOfPlayerVector].setPhase("turn");//set the phase of player
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);//print out

            aggressivePlayer.redeployment(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                          &player.vplayer);//get redeployment to set the troop

            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            //print out the info
            br();


            player.vplayer[indexOfPlayerVector].setPhase("conquer");
            //set the phase to conquer
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);//print out

            aggressivePlayer.conquers(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                      &player.vplayer);//call the conquer function in aggressive class
            //call aggressive conquer class
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();

            player.vplayer[indexOfPlayerVector].setPhase("coin");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);

            aggressivePlayer.scores(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                    &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);


        } else if (player.vplayer[indexOfPlayerVector].getStrategyBehaviour() == 2) {//defensive

            //    player.vplayer[indexOfPlayerVector].setTurn(j);
            player.vplayer[indexOfPlayerVector].setPhase("turn");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);

            defensePlayer.redeployment(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                       &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("conquer");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            defensePlayer.conquers(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                   &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("coin");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            defensePlayer.scores(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                 &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);


        } else if (player.vplayer[indexOfPlayerVector].getStrategyBehaviour() == 3) {//Moderate


            //   player.vplayer[indexOfPlayerVector].setTurn(j);
            player.vplayer[indexOfPlayerVector].setPhase("turn");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            moderatePlayer.redeployment(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                        &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("conquer");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            moderatePlayer.conquers(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                    &player.vplayer);//change   <~~ occupied
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("coin");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            moderatePlayer.scores(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion, &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
        } else if (player.vplayer[indexOfPlayerVector].getStrategyBehaviour() == 4) {




            //     player.vplayer[indexOfPlayerVector].setTurn(j);
            player.vplayer[indexOfPlayerVector].setPhase("turn");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            randomPlayer.redeployment(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                      &player.vplayer);
            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("conquer");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            randomPlayer.conquers(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion,
                                  &player.vplayer);//change   <~~ occupied

            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);
            br();


            player.vplayer[indexOfPlayerVector].setPhase("coin");
            player_pointer->notify(&player.vplayer[indexOfPlayerVector]);
            randomPlayer.scores(&player.vplayer[indexOfPlayerVector], player, &player.vnodeRegion, &player.vplayer);

            veiwer.getPlayerInfoAndShowOccupiedregion(player.vplayer[indexOfPlayerVector].getidPlayer(), player);


        }
        cout << "the Player " << player.vplayer[indexOfPlayerVector].getidPlayer() << " and "
             << player.vplayer[indexOfPlayerVector].getpopulation()
             << endl;
    }//finsih tempStorage

        player_pointer->notifyStatic(&player.vplayer,maploader.nbline);
        player_pointer->detach();

    }//turn 2-10 endloop



    //this is how to implement OberserverDecorator, I didn't use it in the assignment
    //hod = new HandsObserverDecorator(PhaseObserver());
    //player_pointer->attach(hod);




    player.declare_winner(); //declare who is winner
    player.del_pointer();//del pointer
    player.vnodeRegion.clear();//clean up vnodeRegion
    player.vnodeRegion.shrink_to_fit();//clean up vnodeRegion Capacity
    player.vplayer.clear();//clean up vplayer
    player.vplayer.shrink_to_fit();//clean up vplayer Capacity
    po=NULL;//set to Null
    so=NULL;//set to Null
    delete(po);//delete po pointer
    delete(so);//delete so pointer
    cout << "end game" << endl;

}


void Interraction::br() {
    cout<<"▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"<<endl;
}