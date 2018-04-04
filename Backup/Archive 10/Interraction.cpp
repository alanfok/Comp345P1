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

        x = map;
        player.maploader.setmap(x);//important don't erase
        maploader.setmap(x);//important don't erase
        player.enter_race_sp_to_vector();//important don't erase
        player.set_vnodeRegion_Vector(player.maploader.nbline);
        br();
        player.prints();
        br();










        for (int i = 0; i < nbplayer; ++i) {

            player.setRace_population(0);
            nb_pop = 0;
            player.vrace_vspecialpower_print();
            cout << "pick race" << endl;
            cin >> nbOfracetaking;
            cout << "This race you picking us " << player.getvrace(nbOfracetaking) << " "
                 << player.getvspecialpower(nbOfracetaking) << endl;
            victorycoin = 5;
            for (int i = 1; i < nbOfracetaking; i++) {
                race_coin[i] += 1;
                victorycoin--;
            }
            victorycoin += race_coin[nbOfracetaking];
            race_coin[nbOfracetaking] = 0;
            player.race_population_determind(player.getvrace(nbOfracetaking), player.getvspecialpower(nbOfracetaking));
            nb_pop = player.getRace_population();
            cout << "You have " << nb_pop << " poulation" << endl;
            player.pickup(i, victorycoin, nb_pop, player.getvspecialpower(nbOfracetaking),
                          player.getvrace(nbOfracetaking), false);//function calling
            player.tempNbIndex = i;//for strategy purpose
            player.shift(nbOfracetaking);
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            first_time_edge = true;
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
                aggressivePlayer.pickupRaceNSp(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                aggressivePlayer.firstEdge(&player.vplayer[i], player,&player.vnodeRegion,&player.vplayer);
                aggressivePlayer.conquers(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
           //     aggressivePlayer.redeployment(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);

            } else if (input == 2) {
                  defensePlayer.pickupRaceNSp(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                defensePlayer.firstEdge(&player.vplayer[i], player,&player.vnodeRegion,&player.vplayer);
                defensePlayer.conquers(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                        defensePlayer.redeployment(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);

            } else if (input == 3) {
                  moderatePlayer.pickupRaceNSp(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                 moderatePlayer.firstEdge(&player.vplayer[i], player,&player.vnodeRegion,&player.vplayer);
                        moderatePlayer.conquers(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                moderatePlayer.redeployment(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);



            } else if (input == 4) {
                //humanPlayer.pickupRaceNSp(player.vplayer[i],player);
            } else {
                 randomPlayer.pickupRaceNSp(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                randomPlayer.firstEdge(&player.vplayer[i], player,&player.vnodeRegion,&player.vplayer);
                randomPlayer.conquers(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);
                randomPlayer.redeployment(&player.vplayer[i],player,&player.vnodeRegion,&player.vplayer);




            }
            player.test1();
            cout << "the Player " << player.vplayer[i].getidPlayer() << " and " << player.vplayer[i].getpopulation()
                 << endl;
        }

        //turn 2-10
        player.token_sort();
        //for (int j = 2; j <+10 ; ++j) {//2-10 loop
        for (int k = 0; k < player.sortbyvplayercoin.size(); ++k) {
            for (int l = 0; l <player.vplayer.size() ; ++l) {
                if(player.sortbyvplayercoin[k].getidPlayer()==player.vplayer[l].getidPlayer()) {
                     temp_id = player.sortbyvplayercoin[k].getidPlayer();
                }
                if(player.vplayer[temp_id-1].getDecline()==true){

                    for (int i = 0; i < nbplayer; ++i) {

                        player.setRace_population(0);
                        nb_pop = 0;
                        player.vrace_vspecialpower_print();
                        cout << "pick race" << endl;
                        cin >> nbOfracetaking;
                        cout << "This race you picking us " << player.getvrace(nbOfracetaking) << " "
                             << player.getvspecialpower(nbOfracetaking) << endl;
                        victorycoin = 5;
                        for (int i = 1; i < nbOfracetaking; i++) {
                            race_coin[i] += 1;
                            victorycoin--;
                        }
                        victorycoin += race_coin[nbOfracetaking];
                        race_coin[nbOfracetaking] = 0;
                        player.race_population_determind(player.getvrace(nbOfracetaking), player.getvspecialpower(nbOfracetaking));
                        nb_pop = player.getRace_population();
                        cout << "You have " << nb_pop << " poulation" << endl;
                        player.vplayer[temp_id-1].setpopulation(nb_pop);
                        player.vplayer[temp_id-1].setrace(player.getvrace(nbOfracetaking));
                        player.vplayer[temp_id-1].setspecialpower(player.getvspecialpower(nbOfracetaking));


                        //function calling
                        player.tempNbIndex = i;//for strategy purpose
                        player.shift(nbOfracetaking);
                }





                //strategy
                cout << "Select the player type\n"
                        "Press 1:AggressivePlayer\n"
                        "Press 2:DefensivePlayer\n"
                        "Press 3:ModeratePlaye\n"
                        "Press 4:HumanPlayer\n"
                        "Press 5:RandomPlayer\n"
                     << endl;//strategy
                cin>>input;

                if (input < 0 || input > 5) {
                    cout << "input is invalid" << endl;
                } else if (input == 1) {
                    aggressivePlayer.redeployment(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    aggressivePlayer.conquers(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);


                } else if (input == 2) {
                    defensePlayer.redeployment(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    defensePlayer.conquers(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);

                } else if (input == 3) {
                    moderatePlayer.pickupRaceNSp(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    moderatePlayer.redeployment(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    moderatePlayer.conquers(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);

                } else if (input == 4) {
                    //humanPlayer.pickupRaceNSp(player.vplayer[temp_id-1],player);
                } else {
                    randomPlayer.pickupRaceNSp(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    randomPlayer.redeployment(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                    randomPlayer.conquers(&player.vplayer[temp_id-1],player,&player.vnodeRegion,&player.vplayer);
                }
                cout << "the Player " << player.vplayer[temp_id-1].getidPlayer() << " and " << player.vplayer[temp_id-1].getpopulation()
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



        exit(0);

    }
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
