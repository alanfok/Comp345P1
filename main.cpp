#include <iostream>
#include "Maps.h"
#include "Maploader.h"
#include "Player.h"
#include "Interraction.h"
#include "ListofPlayer.h"
#include "Die.h"
#include "Tokens.h"
#include <exception>
using namespace std;
int main() {

    int nbPlayer;//lock for test
    int z;
    int input;
    int race_randam_picking;
    string race_banner [6];
    string map="";
    bool check=false;
    bool firstplay=true;
    Maploader maploader;
    Tokens tokens;
    Interraction interraction;
    Maps maps;
    cout<<"  ▉▉▉▉   ▉▉▉ ▉▉▉  ▉▉▉▉▉▉  ▉▉  ▉▉     ▉▉   ▉▉   ▉▉   ▉▉▉▉▉   ▉▉     ▉▉     ▉▉\n"<<
          " ▉▉      ▉▉ ▉ ▉▉  ▉▉  ▉▉  ▉▉  ▉▉      ▉▉  ▉▉  ▉▉   ▉▉   ▉▉  ▉▉▉▉▉  ▉▉     ▉▉\n"<<
          "  ▉▉▉▉   ▉▉ ▉ ▉▉  ▉▉  ▉▉  ▉▉  ▉▉       ▉  ▉▉  ▉    ▉▉   ▉▉  ▉▉     ▉▉   ▉▉▉▉\n"<<
          "     ▉▉  ▉▉   ▉▉  ▉▉  ▉▉  ▉▉  ▉▉        ▉ ▉▉ ▉     ▉▉   ▉▉  ▉▉     ▉▉   ▉  ▉\n"<<
          "  ▉▉▉▉   ▉▉   ▉▉  ▉▉▉▉▉▉▉ ▉▉  ▉▉         ▉  ▉       ▉▉▉▉▉   ▉▉     ▉▉   ▉▉▉▉  "<<endl;



    cout<< "how many people play the game"<<endl;
    //cin>>nbPlayer;

    do{
        cin>>nbPlayer;
        //cout << nbPlayer;
        try {
            if(cin.fail()) {
                cin.clear();
                throw nbPlayer;
                // if the input is not an integer, an error is thrown
                // claudia
            }
            else if((nbPlayer>5||nbPlayer<2) && cin.fail() == false){

                throw nbPlayer;
                // throws an error if the number of players is greater than
                // 5 or less than 2.
                // claudia
            }
            else if(nbPlayer == 2){map= "2map.txt";
                check=true;
                // set checking to true and get out of the while loop since
                // there is no error here
                // load the appropriate map
                // claudia
            }
            else if(nbPlayer == 3){map= "3map.txt";
                check=true;
                // set checking to true and get out of the while loop since
                // there is no error here
                // load the appropriate map
                // claudia
            }
            else if(nbPlayer == 4){map= "4map.txt";
                check=true;
                // set checking to true and get out of the while loop since
                // there is no error here
                // load the appropriate map
                // claudia
            }
            else if(nbPlayer == 5){map= "5map.txt";
            check=true;
                // set checking to true and get out of the while loop since
                // there is no error here
                // load the appropriate map
                // claudia
            }
            // claudia : fixed position of the code
            /*else{
                throw nbPlayer;

            }*/

        }catch (int nbplayer){
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"The Entry is Invalid, Please try again."<<endl;
            // claudia : Fixed Grammar and made it easier to understand
            cin.clear();
            // getting rid of the error flag
            // claudia
        }



    }while(check==false);


    interraction.setplayer(map,nbPlayer);







}


