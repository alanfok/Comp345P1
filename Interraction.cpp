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
        cin >> raceSelection;
        cout << "This race you picking us " << player.getvrace(raceSelection) << " "
             << player.getvspecialpower(raceSelection) << endl;
        victorycoin = 5;//start with 5 victory coin
        //using the static array to hold the victory coin ,if player pick the
        //first race , player doesn't need to pay a victory coin
        //if player pick the second , player has to pay one victory coin

        //static array holding the coin

        for (int i = 1; i < raceSelection; i++) {
            race_coin[i] += 1;//put one coin into array
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
        cin >> input;
        //use try and catch
        if (input < 0 || input > 4) {
            cout << "input is invalid" << endl;
        } else if (input == 1) {
           player_pointer=&player;
            lp=&player.vplayer[i];
            po=new PhaseObserver();
            player_pointer->attach(po);
            player_pointer->notify(&player.vplayer[i]);
            aggressivePlayer.pickupRaceNSp(&player.vplayer[i]);
            player_pointer->notify(&player.vplayer[i]);
            br();
            aggressivePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                       &player.vplayer);//change  <~~make sure the player is entry from edge
            veiwer.show_region_are_occupied(player.vplayer[i].getidPlayer(),player);
            br();

            aggressivePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                      &player.vplayer);//change <~~ occupied
            aggressivePlayer.scores(&player.vplayer[i], player, &player.vnodeRegion,
                                    &player.vplayer);
        } else if (input == 2) {
            defensePlayer.pickupRaceNSp(&player.vplayer[i]);
            defensePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                    &player.vplayer);//change  <~~make sure the player is entry from edge
            defensePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                   &player.vplayer);//change  <~~ occupied
            defensePlayer.redeployment(&player.vplayer[i], player, &player.vnodeRegion,
                                       &player.vplayer);
            defensePlayer.scores(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);

        } else if (input == 3) {
            moderatePlayer.pickupRaceNSp(&player.vplayer[i]);
            moderatePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                     &player.vplayer);//change  <~~make sure the player is entry from edge
            moderatePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                    &player.vplayer);//change   <~~ occupied

        } else {
            randomPlayer.pickupRaceNSp(&player.vplayer[i]);
            randomPlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion,
                                   &player.vplayer);//change  <~~make sure the player is entry from edge
            randomPlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion,
                                  &player.vplayer);//change   <~~ occupied

        }
        // player.test1();<~~~~ del
        cout << "the Player " << player.vplayer[i].getidPlayer() << " and " << player.vplayer[i].getpopulation()
             << endl;
    }

    //turn 2-10
    player.token_sort();
    //for (int j = 2; j <+10 ; ++j) {//2-10 loop
    for (int k = 0; k < player.sortbyvplayercoin.size(); ++k) {
        for (int l = 0; l < player.vplayer.size(); ++l) {

            if (player.vplayer[k].getidPlayer() == player.vplayer[l].getidPlayer()) {
                temp_id = player.sortbyvplayercoin[k].getidPlayer();
            }


            //for decline <~~add to claudia computer
            if (player.vplayer[temp_id - 1].getDecline() == true &&
                player.vplayer[temp_id - 1].getdecline_lock()) {//for player object who select decline

                for (int i = 0; i < nbplayer; ++i) {
                    player.setRace_population(0);
                    numberOfPopulation = 0;
                    player.vrace_vspecialpower_print();
                    cout << "pick race" << endl;
                    cin >> raceSelection;
                    cout << "This race you picking us " << player.getvrace(raceSelection) << " "
                         << player.getvspecialpower(raceSelection) << endl;
                    for (int i = 1; i < raceSelection; i++) {
                        race_coin[i] += 1;
                        player.vplayer[temp_id - 1].setvictoryCoins(
                                player.vplayer[temp_id - 1].getvictoryCoins() - 1);
                    }
                    player.vplayer[temp_id - 1].setvictoryCoins(
                            player.vplayer[temp_id - 1].getvictoryCoins() + race_coin[raceSelection]);
                    race_coin[raceSelection] = 0;
                    player.race_population_determind(player.getvrace(raceSelection),
                                                     player.getvspecialpower(raceSelection));
                    numberOfPopulation = player.getRace_population();
                    cout << "You have " << numberOfPopulation << " poulation" << endl;
                    player.vplayer[temp_id - 1].setspecialpower(player.getvspecialpower(raceSelection));
                    player.vplayer[temp_id - 1].setrace(player.getvspecialpower(raceSelection));
                    player.vplayer[temp_id - 1].setpopulation(numberOfPopulation);
                    player.vplayer[temp_id - 1].setdecline_lock(1);//locked it
                    player.shift(raceSelection);


                }
                //decline end
                //strategy
                cout << "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"
                        "▉Select the player type         ▉\n"
                        "▉Press 1:AggressivePlayer       ▉\n"
                        "▉Press 2:DefensivePlayer        ▉\n"
                        "▉Press 3:ModeratePlaye          ▉\n"
                        "▉Press 4:RandomPlayer           ▉\n"
                        "▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"
                     << endl;//strategy
                cin >> input;

                if (input < 0 || input > 5) {
                    cout << "input is invalid" << endl;
                } else if (input == 1) {//Aggressive
                    aggressivePlayer.redeployment(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                                  &player.vplayer);
                    aggressivePlayer.conquers(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                              &player.vplayer);


                } else if (input == 2) {//Defensive
                    defensePlayer.redeployment(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                               &player.vplayer);
                    defensePlayer.conquers(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                           &player.vplayer);


                } else if (input == 3) {//Moderate
                    moderatePlayer.pickupRaceNSp(&player.vplayer[temp_id - 1]);


                } else if (input == 4) {
                    //humanPlayer.pickupRaceNSp(player.vplayer[temp_id-1],player);
                } else {//RandomPlayer
                    randomPlayer.pickupRaceNSp(&player.vplayer[temp_id - 1]);
                }
                cout << "the Player " << player.vplayer[temp_id - 1].getidPlayer() << " and "
                     << player.vplayer[temp_id - 1].getpopulation()
                     << endl;
            }


        }

// }//turn 2-10 endloop

        player.declare_winner(); //declare who is winner
        player.del_pointer();
        player.vnodeRegion.clear();
        player.vnodeRegion.shrink_to_fit();
        player.vplayer.clear();
        player.vplayer.shrink_to_fit();
        cout << "end game" << endl;

    }
}

void Interraction::br() {
    cout<<"▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"<<endl;
}