//
// Created by fok poon kai on 2018-02-03.
//

#ifndef COMP345P1_MAPLOADER_H
#define COMP345P1_MAPLOADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Maps.h"
#include "NodeRegion.h"
using   namespace   std;

class Maploader {
public:
    Maps maps;

    int nbline=0;
    bool isLostTribe = false;

    void occup(int i,int playerID);
    void setmap(string map_select);
    //string *region_status;
    vector <string> region_status;
    vector <string> adjact;// claudia
    string *losttride;
   // void enter_to_Object();
    void pointer_del();
    void del_losttride();
private:
    void regiondeternment(string map_select);
    void set_into_array(string map_select);


};



#endif //COMP345P1_MAPLOADER_H
