#include <iostream>
#include "Maps.h"
#include "Maploader.h"
#include "Player.h"
#include "Interraction.h"
#include "ListofPlayer.h"
#include "Die.h"
#include "Tokens.h"
#include <exception>
#include <typeinfo>
using namespace std;
int main() {

    int nbPlayer;//lock for test
    int z;
    int input;
    int race_randam_picking;
    string race_banner[6];
    string map = "";
    bool check = false;
    bool firstplay = true;
    Maploader maploader;
    Tokens tokens;
    Interraction interraction;
    Maps maps;
    cout << "  ▉▉▉▉   ▉▉▉ ▉▉▉  ▉▉▉▉▉▉  ▉▉  ▉▉     ▉▉   ▉▉   ▉▉   ▉▉▉▉▉   ▉▉     ▉▉     ▉▉\n" <<
         " ▉▉      ▉▉ ▉ ▉▉  ▉▉  ▉▉  ▉▉  ▉▉      ▉▉  ▉▉  ▉▉   ▉▉   ▉▉  ▉▉▉▉▉  ▉▉     ▉▉\n" <<
         "  ▉▉▉▉   ▉▉ ▉ ▉▉  ▉▉  ▉▉  ▉▉  ▉▉       ▉  ▉▉  ▉    ▉▉   ▉▉  ▉▉     ▉▉   ▉▉▉▉\n" <<
         "     ▉▉  ▉▉   ▉▉  ▉▉  ▉▉  ▉▉  ▉▉        ▉ ▉▉ ▉     ▉▉   ▉▉  ▉▉     ▉▉   ▉  ▉\n" <<
         "  ▉▉▉▉   ▉▉   ▉▉  ▉▉▉▉▉▉▉ ▉▉  ▉▉         ▉  ▉       ▉▉▉▉▉   ▉▉     ▉▉   ▉▉▉▉  " << endl;


    cout << "how many people play the game" << endl;
    cin >> nbPlayer;


    /*if (cin.fail()) {
        cout << "NOT INT"<<endl;
    } else{
        cin>>nbPlayer;
    }*/
// TO DO :FIX CHAR ERRRO
    do{
        cin>>nbPlayer;

        try {
            if(nbPlayer>5||nbPlayer<2){
                throw nbPlayer;
                // throws an error if the number of players is greater than
                // 5 or less than 2.
                // claudia
            }
            else if(cin.fail()){
                break;
                cout << "ASDFAS" << endl;
                throw nbPlayer;

                // if the input is not an integer, an error is thrown
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
            else{
                cout << "ASDF";
                throw nbPlayer;

            }

        }catch (int nbplayer){
            cout<<"The Entry is Invalid, Please try again."<<endl;
            // claudia : Fixed Grammar and made it easier to understand

            cin.clear();
            cin.ignore(1);
            //check = true;
            //break;

            // getting rid of the error flag
            // claudia
        }
        catch (char nbplayer)
        {
            // all others
        }


    }while(check==false);


    interraction.setplayer(map,nbPlayer);







}


