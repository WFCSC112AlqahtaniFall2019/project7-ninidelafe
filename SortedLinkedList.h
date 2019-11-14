//
// Created by Nini de la Fe on 11/7/19.
//

#ifndef PROJECT7_SORTEDLINKEDLIST_H
#define PROJECT7_SORTEDLINKEDLIST_H

#include <string>
#include "Data.h"
#include "LinkedList.h"

using namespace std;
class SortedLinkedList : public LinkedList {
public:
    SortedLinkedList();
    void insertSorted(Data& da);



};


#endif //PROJECT7_SORTEDLINKEDLIST_H
