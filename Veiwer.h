//
// Created by fok poon kai on 2018-03-21.
//

#ifndef COMP345P1_VEIWER_H
#define COMP345P1_VEIWER_H

#include "Player.h"
#include <iostream>

class Veiwer{


public:
    void getPlayerInfoAndShowOccupiedregion(int nb, Player py);
    void showAllPlayerInformation(Player py);
private:
    void get_player_infomation(int nb, Player py);
    void show_region_are_occupied(int nb,Player py);

};







#endif //COMP345P1_VEIWER_H
