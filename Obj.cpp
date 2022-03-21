#include "Obj.h"

Obj::Obj(){
    tally = 0;
}

Obj::~Obj(){}

void Obj::AddOne(){
    ++tally;
}

void Obj::printTally(){
    std::cout << tally;
}
