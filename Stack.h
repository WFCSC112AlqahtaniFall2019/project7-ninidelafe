//
// Created by Nini de la Fe on 11/7/19.
//

#ifndef PROJECT7_STACK_H
#define PROJECT7_STACK_H

#include "LinkedList.h"
#include "Data.h"

using namespace std;
class Stack : public LinkedList {

public:
    Stack(); //default constructor
    void push_head(Data& da);
    bool pop_head(Data& da);

};


#endif //PROJECT7_STACK_H
