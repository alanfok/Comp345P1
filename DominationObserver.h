//
// Created by Claudia Feochari on 2018-04-07.
//

#ifndef COMP345P1_DOMINATIONOBSERVER_H
#define COMP345P1_DOMINATIONOBSERVER_H

#include "Component.h"

class DominationObserver: public Component
{
public:
    DominationObserver();
    ~DominationObserver();

    void showIceCream();
};

#endif //COMP345P1_DOMINATIONOBSERVER_H
