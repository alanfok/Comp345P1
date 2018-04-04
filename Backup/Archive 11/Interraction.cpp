//
// Created by fok poon kai on 2018-03-09.
//
//the vectors and node class called in player class
//so every time u call the vector value, u need call player.vplayer
// hava a bugs to occupied
//or player.vnoderegion
//
#include "Interraction.h"
#include <memory>

void Interraction ::setplayer(string map,int nbplayer) {

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

    cout << "Select Play Type:\n"
            "Press 1:Automated Player Play\n"
            "Press 2:Regular Custom Play\n"
         << endl;
    cin >> select_play_type;

    if (select_play_type == 1) {// AI playing
        for (int i = 0; i < nbplayer; ++i) {
            player.setRace_population(0);
            nb_pop = 0;
            player.vrace_vspecialpower_print();
            cout << "pick race" << endl;
            cin >> nbOfracetaking;
            cout << "This race you picking us " << player.getvrace(nbOfracetaking) << " "
                 << player.getvspecialpower(nbOfracetaking) << endl;
            victorycoin = 5;//start with 5 victory coin
             //using the static array to hold the victory coin ,if player pick the
            //first race , player doesn't need to pay a victory coin
            //if player pick the second , player has to pay one victory coin
            //static array holding the coin

            for (int i = 1; i < nbOfracetaking; i++) {
                race_coin[i] += 1;//put one coin into array
                victorycoin--;//minus the coin
            }
            victorycoin += race_coin[nbOfracetaking];//victory plus the coin that the array holding
            race_coin[nbOfracetaking] = 0;//reset the index of array that the coin holding =0;
            player.race_population_determind(player.getvrace(nbOfracetaking), player.getvspecialpower(nbOfracetaking));
            //determind how many popualation that race and special power combine
            nb_pop = player.getRace_population();//get the population from player class
            cout << "You have " << nb_pop << " poulation" << endl;

            player.pickup(i, victorycoin, nb_pop, player.getvspecialpower(nbOfracetaking),
                          player.getvrace(nbOfracetaking), false);//function calling,create the player object
            player.tempNbIndex = i;//for strategy purpose
            player.shift(nbOfracetaking);//shift up the race and special power to replace that player toke
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            first_time_edge = true;//
            tempvplayerid = player.vplayer[i].getidPlayer();//temp playid
            tempvplayerpop = player.vplayer[i].getpopulation();//temp player pop

            //strategy
            cout << "Select the player type\n"
                    "Press 1:AggressivePlayer\n"
                    "Press 2:DefensivePlayer\n"
                    "Press 3:ModeratePlaye\n"
                    "Press 4:HumanPlayer\n"
                    "Press 5:RandomPlayer\n"
                 << endl;//strategy
            cin >> input;
            if (input < 0 || input > 5) {
                cout << "input is invalid" << endl;
            } else if (input == 1) {
                aggressivePlayer.pickupRaceNSp(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                aggressivePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change  <~~make sure the player is entry from edge
                aggressivePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change <~~ occupied


            } else if (input == 2) {
                  defensePlayer.pickupRaceNSp(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                defensePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change  <~~make sure the player is entry from edge
                defensePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change  <~~ occupied


            } else if (input == 3) {
                  moderatePlayer.pickupRaceNSp(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                moderatePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change  <~~make sure the player is entry from edge
                moderatePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change   <~~ occupied





            } else if (input == 4) {//for future purpose
                //humanPlayer.pickupRaceNSp(player.vplayer[i],player);
            } else {
                 randomPlayer.pickupRaceNSp(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);
                moderatePlayer.firstEdge(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change  <~~make sure the player is entry from edge
                moderatePlayer.conquers(&player.vplayer[i], player, &player.vnodeRegion, &player.vplayer);//change   <~~ occupied

            }
           // player.test1();<~~~~ del
            cout << "the Player " << player.vplayer[0].getidPlayer() << " and " << player.vplayer[0].getpopulation()
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
                if (player.vplayer[temp_id - 1].getDecline() == true && player.vplayer[temp_id - 1].getdecline_lock()) {//for player object who select decline

                    for (int i = 0; i < nbplayer; ++i) {
                        player.setRace_population(0);
                        nb_pop = 0;
                        player.vrace_vspecialpower_print();
                        cout << "pick race" << endl;
                        cin >> nbOfracetaking;
                        cout << "This race you picking us " << player.getvrace(nbOfracetaking) << " "
                             << player.getvspecialpower(nbOfracetaking) << endl;
                        for (int i = 1; i < nbOfracetaking; i++) {
                            race_coin[i] += 1;
                            player.vplayer[temp_id - 1].setvictoryCoins(
                                    player.vplayer[temp_id - 1].getvictoryCoins() - 1);
                        }
                        player.vplayer[temp_id - 1].setvictoryCoins(
                                player.vplayer[temp_id - 1].getvictoryCoins() + race_coin[nbOfracetaking]);
                        race_coin[nbOfracetaking] = 0;
                        player.race_population_determind(player.getvrace(nbOfracetaking),
                                                         player.getvspecialpower(nbOfracetaking));
                        nb_pop = player.getRace_population();
                        cout << "You have " << nb_pop << " poulation" << endl;
                        player.vplayer[temp_id - 1].setspecialpower(player.getvspecialpower(nbOfracetaking));
                        player.vplayer[temp_id - 1].setrace(player.getvspecialpower(nbOfracetaking));
                        player.vplayer[temp_id - 1].setpopulation(nb_pop);
                        player.vplayer[temp_id - 1].setdecline_lock(1);//locked it
                        player.shift(nbOfracetaking);


                    }
                    //decline end
                    //strategy
                    cout << "Select the player type\n"
                            "Press 1:AggressivePlayer\n"
                            "Press 2:DefensivePlayer\n"
                            "Press 3:ModeratePlaye\n"
                            "Press 4:HumanPlayer\n"
                            "Press 5:RandomPlayer\n"
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
                        moderatePlayer.pickupRaceNSp(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                                     &player.vplayer);


                    } else if (input == 4) {
                        //humanPlayer.pickupRaceNSp(player.vplayer[temp_id-1],player);
                    } else {//RandomPlayer
                        randomPlayer.pickupRaceNSp(&player.vplayer[temp_id - 1], player, &player.vnodeRegion,
                                                   &player.vplayer);
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
            cout<<"end game"<<endl;

        }
    }else if(select_play_type == 2) {
            for (int i = 0; i < nbplayer; ++i) {
                cout << "PLAYER " << i + 1 << endl;
                turn = 1;
                player.setRace_population(0);
                nb_pop = 0;
                player.vrace_vspecialpower_print();
                cout << "pick race" << endl;
                cin >> nbOfracetaking;

                tempvrace = player.getvrace(nbOfracetaking);
                tempsp = player.getvspecialpower(nbOfracetaking);
                victorycoin = 5;
                for (int i = 1; i < nbOfracetaking; i++) {
                    race_coin[i] += 1;
                    victorycoin--;
                }


                victorycoin += race_coin[nbOfracetaking];
                cout << victorycoin << endl;


                race_coin[nbOfracetaking] = 0;
                player.race_population_determind(player.getvrace(nbOfracetaking),
                                                 player.getvspecialpower(nbOfracetaking));
                nb_pop = player.getRace_population();


                player.pickup(i, victorycoin, nb_pop, player.getvspecialpower(nbOfracetaking),
                              player.getvrace(nbOfracetaking), false);//function calling
                player.shift(nbOfracetaking);
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                first_time_edge = true;
                tempvplayerid = player.vplayer[i].getidPlayer();//temp playid
                tempvplayerpop = player.vplayer[i].getpopulation();//temp player pop
                cout << player.vnodeRegion[i].getplayer_race();
                //observers
                observer.attach(player.vplayer[i]);

                do {
                    //veiwer.get_player_infomation(tempvplayerid, player);
                    observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace, tempsp, nb_pop,
                                    tempvplayerid, player, turn, " loosing coins", " ", lostRegions);
                    br();
                    cout << "Which region you want to Occupied first(Hint: You to to occuppy from the edge first)"
                         << endl;
                    cin >> input;
                    input -= 1;//the region u want to occupited
                    veiwer.get_individual_region_info(input, player);


                    if (maploader.adjact[input].compare("y") == 0) {

                        // check cost 1 or 2 that population cost
                        if (player.vnodeRegion[input].getregion_status().compare("____water__") != 0 ||
                            player.vplayer[i].getspecialPower().compare("Seafaring") == 0) {
                            population_cost(tempvplayerid, input);
                            cout << "it will cost you " << temp_population << " population.\n Do you wanna to "
                                    "Occupied it?\n Press 1 :Yes \n Press 2 :None" << endl;
                            cin >> input_select;
                            if (input_select == 2) {//No
                                cout << "select again" << endl;
                            } else if (input_select == 1) {//if yes
                                cout << "how many population you want to occupy" << endl;
                                cin >> input_temp_enter_pop;
                                if (input_temp_enter_pop > tempvplayerpop) {
                                    cout << "player population cannot be negative" << endl;
                                } else {
                                    if (player.vnodeRegion[i].getid_player() != 0) {
                                        lostRegions.push_back(player.vnodeRegion[i].getid_player());
                                        cout << "loosig region" << endl;
                                        cout << lostRegions[0] << endl;
                                        // add loosing regions here
                                        /*observer.update(observer.getPlayerList(),playercounter,nbplayer
                                                ,tempvrace,tempsp,nb_pop,tempvplayerid,player,turn," coins remain same");*/
                                    }

                                    observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace,
                                                    tempsp, nb_pop, tempvplayerid, player, turn, " coins remain same",
                                                    " conquers region", lostRegions);

                                    //here :  conquering success so pass in parameter conquers
                                    player.return_puplation_to_occupied_player(input);
                                    //return the population to orginal player
                                    if (input_temp_enter_pop > temp_population) {
                                        player.conquers(input, tempvplayerid, input, input_temp_enter_pop);
                                        first_time_edge = false;//outofwhileloop
                                        veiwer.get_individual_region_info(input, player);
                                        maploader.losttride[input] = "_none__";
                                        tempvplayerpop -= input_temp_enter_pop;//reduce the population
                                    }
                                }
                            } else {
                                cerr << "the input is invalid" << endl;

                            }
                        } else {
                            cout << " The region is water and you don't have special power" << endl;
                        }//check water and special power
                    } else { cout << "the region is not edge" << endl; }
                } while (first_time_edge == true);

                first_time_edge = true;//reset
                veiwer.get_individual_region_info(input, player);
                player.prints();


                /*
                 * occupied
                 * */

                flag_Occ = false;
                do {
                    //veiwer.get_player_infomation(tempvplayerid, player);
                    /*observer.update(observer.getPlayerList(),playercounter,nbplayer
                            ,tempvrace,tempsp,nb_pop,tempvplayerid,player,turn," coins remain same", lostRegions );*/
                    // claudia

                    cout << "Do you want to Occupy another region? \nPress 1 : yes\nPress 2 : NO" << endl;
                    cin >> input_select;
                    if (input_select == 1) {
                        player.prints();

                        /*observer.update(observer.getPlayerList(),playercounter,nbplayer
                                ,tempvrace,tempsp,nb_pop,tempvplayerid,player,turn,"");*/
                        //claudia

                        cout << "Enter form" << endl;//from which region to which region
                        cin >> input_from;
                        input_from -= 1;
                        cout << "Enter to" << endl;//to which region
                        cin >> input_to;
                        input_to -= 1;
                        //isSideEdge = player.first_time_check_side(input_to);
                        if (maploader.maps.pt[input_from][input_from] == tempvplayerid ||
                            maploader.adjact[input_from].compare("y") ==
                            0) {//check the region is occupied by player or not
                            if ((player.vnodeRegion[input_to].getregion_status().compare("____water__") != 0 ||
                                 player.vplayer[i].getspecialPower().compare("Seafaring") == 0)) {
                                edge_check = player.edgecheck(input_from, input_to);//check edge is true or false
                                if (edge_check == true) {
                                    if (maploader.maps.pt[input_to][input_to] == 0) {//no one occupied
                                        population_cost(tempvplayerid, input_to);
                                        cout << "The region cost " << temp_population << " population. \n"
                                                "How many population you want to occupy??" << endl;
                                        cin >> input_temp_enter_pop;

                                        observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace,
                                                        tempsp, nb_pop, tempvplayerid, player, turn,
                                                        " coins remain same", " conquers region", lostRegions);

                                        if (input_temp_enter_pop > tempvplayerpop) {
                                            cout << "player population cannot be negative" << endl;
                                        } else {
                                            if (temp_population >
                                                input_temp_enter_pop) {//player pop is smaller then region pop
                                                cout << "do you want to throw the dice \nPress 1:yes\nPress 2:No"
                                                     << endl;
                                                cin >> input_select;

                                                if (input_select == 1) {
                                                    int temp_nb_dice = player.getthrowdie();
                                                    int tempnb = temp_nb_dice + input_temp_enter_pop;
                                                    cout << "the dice you thrown get " << tempnb << endl;
                                                    if (tempnb >
                                                        temp_population) {//dice nb + player pop is biger then region pop
                                                        invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                                        flag_Occ = true;
                                                        maploader.losttride[input_to] = "_none__";
                                                        temp_population -= input_temp_enter_pop;
                                                    } else {
                                                        cout << "it's not enough to occupy" << endl;
                                                    }
                                                } else if (input_select == 2) {
                                                    cout << "ok" << endl;
                                                } else {
                                                    cerr << "the input is invalid" << endl;
                                                }
                                            } else {//player pop is biger then region pop
                                                invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                                temp_population -= input_temp_enter_pop;
                                                maploader.losttride[input] = "_none__";
                                            }
                                        }//player has to have to popuplation that he entry

                                    }//no one occupied loop
                                    else {//if the region occupied by another player
                                        population_cost(tempvplayerid, input_to);
                                        //veiwer.get_player_infomation(tempvplayerid, player);
                                        observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace,
                                                        tempsp, nb_pop, tempvplayerid, player, turn,
                                                        " coins remain same", " ", lostRegions);
                                        //claudia
                                        cout << "The region cost " << temp_population << " population. \n"
                                                "How many population you want to occupy??" << endl;
                                        cin >> input_temp_enter_pop;
                                        if (input_temp_enter_pop > tempvplayerpop) {//p
                                            cout << "player population cannot be negative" << endl;
                                        } else {
                                            if (player.vnodeRegion[input_to].getregion_population() >
                                                input_temp_enter_pop) {
                                                cout << "do you want to throw the dice \nPress 1:yes\nPress 2:No"
                                                     << endl;
                                                cin >> input_select;

                                                if (input_select == 1) {
                                                    cout<<"The dice is being thrown now"<<endl;
                                                    int temp_nb_dice = player.getthrowdie();
                                                    int tempnb = temp_nb_dice + input_temp_enter_pop;
                                                    cout << "You get " <<temp_nb_dice<<" and the total is "<<temp_nb_dice + input_temp_enter_pop<< endl;
                                                    if (tempnb >=
                                                        temp_population) {//dice nb + player pop is biger then region pop
                                                        player.return_puplation_to_occupied_player(input_to);
                                                        invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                                        maploader.losttride[input_to] = "_none__";
                                                        flag_Occ = true;
                                                    } else {//player pop is bigger the region pop
                                                        cout << "it's not enough to occupy" << endl;
                                                    }
                                                } else if (input_select == 2) {
                                                    cout << "ok" << endl;
                                                } else {
                                                    cerr << "the input is invalid" << endl;
                                                }
                                            } else {//check the player has more then orgion pop
                                                player.return_puplation_to_occupied_player(input_to);
                                                invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                                maploader.losttride[input_to] = "_none__";
                                            }
                                        }

                                    }
                                    /*check the region is it occupied by another player*/
                                }//edge check true
                                else {
                                    cout << "those regions are not linking together" << endl;
                                }//edge check is Not

                            }//check not water or player special
                            else {
                                cout << "The region is a water and you don't have Seafaring power" << endl;
                            }//it is a water
                        } else {//end occ
                            cout << "you did'n have the region" << endl;

                        }

                    }//yes,end loop
                    else if (input_select == 2) {
                        flag_Occ = true;
                    }//No,end loop
                    else {
                        cerr << "the input is invalid" << endl;


                    }//invaild
                } while (flag_Occ == false);
                flag_Occ = false;
                /*
                 *
                 * Troop Redeployment
                 *
                 * */
                flag_redeployment = false;
                do {
                    veiwer.show_region_are_occupied(tempvplayerid, player);
                    cout << "Do you want to Troop Redeployment \nPress 1: yes\n Press 2:NO " << endl;
                    cin >> input_select;
                    if (input_select == 1) {//yes for Redeploymen
                        veiwer.show_region_are_occupied(tempvplayerid, player);
                        cout << "Select the region u wanna redeploy" << endl;
                        cin >> input;
                        input -= 1;
                        cout << "Select how many population you want withdraw" << endl;
                        cin >> input_temp_enter_pop;
                        /*do the deplayment function*/
                        cout << "Before" << endl;
                        veiwer.get_individual_region_info(input, player);
                        player.withdraw_v2(input, tempvplayerid, input_temp_enter_pop);//withdraw the pop in the region
                        cout << "After" << endl;
                        veiwer.get_individual_region_info(input, player);
                        cout << "redeploy,\n select the region" << endl;
                        cin >> input;
                        input -= 1;
                        cout << "select the population" << endl;
                        cin >> input_temp_enter_pop;
                        player.redeployment(input, tempvplayerid,
                                            input_temp_enter_pop);//just put the pop in region,class player
                        veiwer.get_individual_region_info(input, player);
                    } else if (input_select == 2) {//no for Redeploymen
                        flag_redeployment = true;//get out for the while loop
                    } else {//invalid
                        cout << "invalid" << endl;
                    }
                    /*stop here, to be continue*/
                } while (flag_redeployment == false);
                flag_redeployment = false;//reset for next time

                veiwer.get_individual_region_info(tempvplayerid, player);

                cout << endl;//br line
                for (int i = 0; i < player.vplayer.size(); i++) {
                    cout << "Player " << player.vplayer[i].getidPlayer() << " victory coin "
                         << player.vplayer[i].getvictoryCoins()
                         << " population " << player.vplayer[i].getpopulation() << " race " << player.vplayer[i].getrace()
                         << endl;
                }
                player.prints();

                cout << "Coin collecting" << endl;
                player.collecttoken(tempvplayerid);//collect the coin to player
                //veiwer.get_player_infomation(tempvplayerid, player);
                observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace, tempsp, nb_pop,
                                tempvplayerid, player, turn, " collecting coins", " ", lostRegions);
                //claudia
            }//player loop turn one
            player.token_sort();//the next turn start of the player who has to most token
            //create the 2-10 turn
            for (int i = 2; i < 11; i++) {
                turn++;
                for (int player_token_sort = 0;
                     player_token_sort < player.sortbyvplayercoin.size(); ++player_token_sort) {//need test
                    cout << player.sortbyvplayercoin[player_token_sort].getidPlayer() << endl;
                    cout << "Player " << player.sortbyvplayercoin[player_token_sort].getidPlayer()
                         << "  is your turn now"
                         << endl;

                    tempvplayerid = player.sortbyvplayercoin[player_token_sort].getidPlayer();
                    tempvplayerpop = player.sortbyvplayercoin[player_token_sort].getpopulation();
                    nextturn = false;
                    if (player.vplayer[tempvplayerid - 1].getDecline() == true) {//if-else decline start


                        player.setRace_population(0);
                        nb_pop = 0;
                        player.vrace_vspecialpower_print();
                        cout << "pick race" << endl;
                        cin >> nbOfracetaking;

                        phase_observer.race_picked
                                (player.getvrace(nbOfracetaking),
                                 player.getvspecialpower(nbOfracetaking));

                        /*cout << "This race you picking us " << player.getvrace(nbOfracetaking) << " "
                             << player.getvspecialpower(nbOfracetaking) << endl;*/
                        // backup

                        victorycoin = player.vplayer[tempvplayerid - 1].getvictoryCoins();
                        for (int i = 1; i < nbOfracetaking; i++) {
                            race_coin[i] += 1;
                            victorycoin--;
                        }
                        victorycoin += race_coin[nbOfracetaking];
                        race_coin[nbOfracetaking] = 0;
                        player.race_population_determind(player.getvrace(nbOfracetaking),
                                                         player.getvspecialpower(nbOfracetaking));
                        nb_pop = player.getRace_population();
                        player.vplayer[tempvplayerid - 1].setrace(player.getvrace(nbOfracetaking));
                        player.vplayer[tempvplayerid - 1].setspecialpower(player.getvspecialpower(nbOfracetaking));
                        player.vplayer[tempvplayerid - 1].setvictoryCoins(victorycoin);
                        player.vplayer[tempvplayerid - 1].setpopulation(nb_pop);
                        player.vplayer[tempvplayerid - 1].setDecline(false);

                    }//if-else decline finish

                    do {//turn
                        //decline function
                        cout << "Do you want to decline\nPress 1 : yes\nPress 2 : NO" << endl;
                        cin >> input_select;
                        if (input_select == 2) {
                            cout << "OK" << endl;
                        } else {
                            player.vplayer[tempvplayerid - 1].setDecline(true);
                            break;
                        }
                        Occupiedcheck2To10 = false;
                        do {//occupied
                            cout << "Do you want to Occupy region? \nPress 1 : yes\nPress 2 : NO" << endl;
                            cin >> input_select;
                            cout << input_select;
                            if (input_select == 1) {
                                pick_pop_during_Occupied2To10 = false;
                                do {//decide pick up the pop that already on region for occupied the new/other player region
                                    //veiwer.get_player_infomation(tempvplayerid, player);
                                    observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace,
                                                    tempsp, nb_pop, tempvplayerid, player, turn, " coins remain same",
                                                    " ", lostRegions);
                                    //claudia
                                    cout
                                            << "do you wanna withdraw pop for your region first\n Press 1 : yes\n Press 2 : NO"
                                            << endl;
                                    cin >> input_select;
                                    if (input_select == 1) {
                                        veiwer.show_region_are_occupied(tempvplayerid, player);
                                        cout
                                                << "which region you wanna withdraw? Hint: at least 1 pop or u will lost the region"
                                                << endl;
                                        cin >> input;
                                        input -= 1;
                                        cout << "Select how many population you want withdraw" << endl;
                                        cin >> input_temp_enter_pop;
                                        if (input_temp_enter_pop > player.vnodeRegion[input].getregion_population()) {
                                            cout << "you can't withdraw pop than more region has!!" << endl;
                                        } else {//withdraw pop >= region pop
                                            player.withdraw_v2(input, tempvplayerid, input_temp_enter_pop);
                                            tempvplayerpop += input_temp_enter_pop;// player pop + pop withdraw from region
                                        }
                                    } else if (input_select == 2) {
                                        cout << "ok" << endl;
                                        pick_pop_during_Occupied2To10 = true;
                                    } else {//select 1

                                        cerr << "invaild" << endl;
                                    }
                                } while (!pick_pop_during_Occupied2To10);
                                // claudia : modified the if and else statement
                                cout << "from where" << endl;
                                cin >> input_from;
                                cout << "to where" << endl;
                                cin >> input_to;
                                input_from -= 1;
                                input_to -= 1;
                                if (maploader.maps.pt[input_from][input_from] != tempvplayerid &&
                                    maploader.adjact[input_from].compare("y") !=
                                    0) {// if the region is not occupied by u and it is
                                    cout << "the region is not on the edge or u are not occupied the region" << endl;
                                } else if (
                                        (player.vnodeRegion[input_to].getregion_status().compare("____water__") == 0 &&
                                         player.vplayer[tempvplayerid].getspecialPower().compare("Seafaring") != 0)) {
                                    cout << "The region is a water and you don't have Seafaring power" << endl;
                                } else if (!player.edgecheck(input_from, input_to)) {
                                    cout << "Those region are not linking tgt" << endl;
                                } else {
                                    population_cost(input_to, tempvplayerid);
                                    cout << "The region cost " << temp_population << " population. \n"
                                            "How many population you want to occupy??" << endl;
                                    cin >> input_temp_enter_pop;//////////
                                    if (input_temp_enter_pop > tempvplayerpop) {
                                        cout << "player population cannot be negative" << endl;
                                    } else {
                                        if (temp_population > input_temp_enter_pop) {
                                            cout << "do you want to throw the dice \nPress 1:yes\nPress 2:No" << endl;
                                            cin >> input_select;
                                            if (input_select == 1) {
                                                int temp_nb_dice = player.getthrowdie();
                                                int tempnb = temp_nb_dice + input_temp_enter_pop;
                                                cout << "You get " << tempnb << endl;
                                                if (tempnb >=
                                                    temp_population) {//dice nb + player pop is biger then region pop
                                                    player.return_puplation_to_occupied_player(input_to);
                                                    invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                                    maploader.losttride[input_to] = "_none__";
                                                    Occupiedcheck2To10 = true;//becuz it's the last one
                                                } else {//player pop is bigger the region pop
                                                    cout << "it's not enough to occupy" << endl;
                                                }

                                            } else if (input_select == 2) {
                                                cout << "ok" << endl;
                                            } else {
                                                cerr << "the input is invalid" << endl;
                                            }// claudia : modified the if and else statement
                                        } else {//check the player has more then orgion pop
                                            player.return_puplation_to_occupied_player(input_to);
                                            invade_pack(input_to, tempvplayerid, input_temp_enter_pop);
                                            maploader.losttride[input_to] = "_none__";
                                        }
                                    }
                                }
                            } else if (input_select == 2) {
                                cout << "ok" << endl;
                                Occupiedcheck2To10 = true;
                            } else {

                                cerr << "invaild" << endl;
                            }
                        } while (!Occupiedcheck2To10);
                        Redeploymentcheck2TO10 = false;
                        do {
                            veiwer.show_region_are_occupied(tempvplayerid, player);
                            cout << "Do you want to Troop Redeployment \nPress 1: yes\n Press 2:NO " << endl;
                            cin >> input_select;
                            if (input_select == 1) {//yes for Redeploymen
                                veiwer.show_region_are_occupied(tempvplayerid, player);
                                cout << "Select the region u wanna redeploy" << endl;
                                cin >> input;
                                input -= 1;
                                cout << "Select how many population you want withdraw" << endl;
                                cin >> input_temp_enter_pop;
                                /*do the deplayment function*/
                                cout << "Before" << endl;
                                veiwer.get_individual_region_info(input, player);
                                player.withdraw_v2(input, tempvplayerid,
                                                   input_temp_enter_pop);//withdraw the pop in the region
                                cout << "After" << endl;
                                veiwer.get_individual_region_info(input, player);//display
                                cout << "redeploy,\n select the region" << endl;
                                cin >> input;
                                input -= 1;
                                cout << "select the population" << endl;
                                cin >> input_temp_enter_pop;
                                player.redeployment(input, tempvplayerid,
                                                    input_temp_enter_pop);//just put the pop in region,class player
                                veiwer.get_individual_region_info(input, player);
                            } else if (input_select == 2) {//no for Redeploymen
                                cout << "ok" << endl;
                                flag_redeployment = true;//get out for the while loop
                            } else {//invalid
                                cout << "invalid" << endl;
                            }
                        } while (!Redeploymentcheck2TO10);
                        // claudia : modified the if and else statement
                    } while (nextturn == false);
                    cout << "Coin collecting" << endl;
                    player.collecttoken(tempvplayerid);//collect the coin to player
                    //veiwer.get_player_infomation(tempvplayerid, player);
                    observer.update(observer.getPlayerList(), playercounter, nbplayer, tempvrace, tempsp, nb_pop,
                                    tempvplayerid, player, turn, " collecting coins", " ", lostRegions);
                    //claudia
                }//playeraround
                player.sortbyvplayercoin.clear();
                player.sortbyvplayercoin.shrink_to_fit();//reduce the memory
                player.token_sort();//the next turn start of the player who has to most token
            }//turn 2-10
            player.declare_winner(); //declare who is winner
            player.del_pointer();
            player.vnodeRegion.clear();
            player.vnodeRegion.shrink_to_fit();
            player.vplayer.clear();
            player.vplayer.shrink_to_fit();
        }

///*
//
// * design pattern
// * cleanup the code
// * declare the winner
// *
// * */

        exit(0);

    }

void Interraction::population_cost(int playerid, int regionid) {
    temp_population=player.special_power_pop_cost_deternment(playerid,regionid);
    temp_population+=player.vnodeRegion[regionid].getregion_population();
    if(player.vnodeRegion[regionid].getregion_status().compare("_mountain__")==0){
        temp_population+=1;
        cout<<"mountain cost 1 more popluation"<<endl;
    }
    if(maploader.losttride[regionid].compare("_LosTri_")==0){
        temp_population+=1;
        cout<<"lost tride cost 1 more popluation"<<endl;
    }

}

void Interraction::invade_pack(int input_to, int tempvplayerid, int temp_occ_pp) {
    player.invade_v2(tempvplayerid, input_to);//in token
    player.conquers_v2(input_to, tempvplayerid, temp_occ_pp);// in player
    tempvplayerpop -= temp_occ_pp;//reduce the population

}


void Interraction::br() {
    cout<<"▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉▉"<<endl;
}