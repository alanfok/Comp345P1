//
// Created by fok poon kai on 2018-02-03.
//
// some ideas and code from http://www.sanfoundry.com/cpp-program-implement-adjacency-matrix/
#include "Maps.h"

void Maps::set_Map(int nbOfregion){
    this->nbOfregion = nbOfregion;
    pt = new int *[nbOfregion];
    for (int i = 0; i < nbOfregion; i++) {
        pt[i] = new int[nbOfregion];
        for (int j = 0; j < nbOfregion; j++) {
            pt[i][j] = 0;
        }
    }
};


void Maps::set_Edge(int firstNode, int secondNode)
{
    if(firstNode >nbOfregion|| secondNode > nbOfregion||
       firstNode >nbOfregion|| secondNode > nbOfregion){

        cout<<"invalid"<<endl;

    }else{
        pt[firstNode-1][secondNode-1]=1;
        pt[secondNode-1][firstNode-1]=1;
    }

};
void Maps::print() {
    int i, j;
    for (i = 0; i < nbOfregion; i++) {
        for (j = 0; j < nbOfregion; j++)
            cout << pt[i][j] << "  ";
        cout << endl;
    }

};
void Maps::occoup(int region,int playerID) {
    pt[region][region]=playerID;
}

void Maps::pointer_del() {
    pt=NULL;
    delete(pt);
}