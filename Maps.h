//
// Created by fok poon kai on 2018-02-03.
//

#ifndef COMP345P1_MAPS_H
#define COMP345P1_MAPS_H

#include <iostream>
#include <vector>
using  namespace std;

class Maps {
public:
    int nbOfregion;
    int **pt;
    void set_Map(int nbOfregion);
    void set_Edge(int firstNode, int secondNode );
    void print();
    void occoup(int region, int playerID);
    void pointer_del();
    vector <int> nbMapRegions {23,30,39,48};
};


#endif //COMP345P1_MAPS_H
