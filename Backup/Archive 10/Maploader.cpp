//
// Created by fok poon kai on 2018-02-03.
//
#include "Maploader.h"
void Maploader::setmap(string map_select) {
    regiondeternment(map_select);
    set_into_array(map_select);

}
//////private
void Maploader::regiondeternment(string map_select) {
    try{
        ifstream file(map_select);

        string line;
        while(getline(file,line)){
            ++nbline;
        }
        file.close();
    }catch (ios_base::failure& e){
        cerr<<"file does not exist"<<endl;
    }
};
//file op code is looked up at C plus plus tutorial and modified

void Maploader::set_into_array(string map_select){
    ifstream sfile(map_select);
    maps.set_Map(nbline);
    losttride = new string [nbline];
    //region_status = new string [nbline];
    //adjact = new string [nbline];
    string arr[nbline][nbline+3];
    for (int i=0;i<nbline;i++){
        for(int j=0;j<nbline+3;j++){
            sfile >> arr[i][j];
        }
    }
    for (int i=0;i<nbline;i++){
        adjact.push_back( arr [i][nbline+1]);
        region_status.push_back(arr[i][0]);
        //region_status[i]=arr[i][0];
        losttride[i]=arr[i][nbline+2];
        for(int j=1;j<nbline+1;j++){
            string x = arr[i][j];
            int y =x.compare("1");
            if(y==0){
                maps.set_Edge(i+1,j);
            }
        }
    }


    // maps.print();

}


//////
void Maploader::occup(int region,int playerID){
    if(maps.pt[region][region]==0){
        maps.occoup(region,playerID);
    }
    // maps.print();

}
void Maploader::pointer_del() {

//    delete [] region_status;
//    region_status=NULL;


    delete [] losttride;
    losttride=NULL;
}
