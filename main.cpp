#include <iostream>
#include "Maps.h"
#include "Maploader.h"
#include "Player.h"
#include "Interraction.h"
#include "ListofPlayer.h"
#include "Die.h"
#include "Tokens.h"
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

    do{
        cin>>nbPlayer;
        try {
            if(nbPlayer>5||nbPlayer<2){
                throw nbPlayer;
            }else if(!cin){
                throw nbPlayer;
            }
            else if(nbPlayer == 5){map= "5map.txt";
            check=true;}
            else if(nbPlayer == 2){map= "2map.txt";
                check=true;}
            else if(nbPlayer == 3){map= "3map.txt";
                check=true;}
            else if(nbPlayer == 4){map= "4map.txt";
            check=true;
            }
        }catch (int nbplayer){
            cout<<"invalid enter,Please enter again."<<endl;
            cin.clear();
            cin.ignore(1);
        }
    }while(check==false);


    interraction.setplayer(map,nbPlayer);







}


