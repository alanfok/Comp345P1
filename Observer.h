//
// Created by fok poon kai on 2018-04-07.
//

#ifndef COMP345P1_OBSERVER_H
#define COMP345P1_OBSERVER_H

//#include "Subject.h"
//#include "ListofPlayer.h"
class Subject;
class ListofPlayer;

class Observer {

public:

    virtual void update(ListofPlayer *pl){
    };

};
#endif //COMP345P1_OBSERVER_H
