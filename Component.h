//
// Created by Claudia Feochari on 2018-04-08.
//

#ifndef COMP345P1_COMPONENT_H
#define COMP345P1_COMPONENT_H

class Component
{
public:
    Component() {}
    ~Component() {}

    virtual void showIceCream()= 0;
    virtual double getPrice() { return this->price; }

private:
    double price = 2.50;
};


#endif //COMP345P1_COMPONENT_H
