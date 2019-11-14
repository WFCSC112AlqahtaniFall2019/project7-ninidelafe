//
// Created by Nini de la Fe on 11/7/19.
//

#include <string>
#include "SortedLinkedList.h"
using namespace std;

//creates a Node pointer and inserts it into a sorted List at the correct place based on the overloaded comparison
//comparison operators in Data.cpp
void SortedLinkedList::insertSorted(Data &da) {

    Node *newData = new Node(da);
    //if the list is empty
    if (head == nullptr) {
        head = newData;
    //if not empty all of the below is run to insert the node in the new location
    } else {
        Node *current = head;
        Node *previous = nullptr;

        //current->data > newData->data
        if (newData->data < current->data) {
            newData->next = head;
            head = newData;
            return;
        }
        //keeps searching for the correct location and going through the list
        previous = current;
        current = current->next;

        while (current) {
            //newData->data > current->data
            if (current->data < newData->data) {
                previous = current;
            }
            current = current->next;
        }

        Node *temp = current;
        newData->next = current;
        previous->next = newData;

    }
}

