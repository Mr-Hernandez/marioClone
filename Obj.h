#pragma once
#include <iostream>

class Obj{
public:
    Obj();
    ~Obj();

    void AddOne();
    void printTally();
private:
    int tally;
};
