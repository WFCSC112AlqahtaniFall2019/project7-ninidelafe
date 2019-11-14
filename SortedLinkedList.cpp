//
// Created by Nini de la Fe on 11/7/19.
//

#include <string>
#include "SortedLinkedList.h"
using namespace std;


//includes a member public function named “insertSorted” takes in a Data object, creates a Node pointer, and
// inserts it into the Sorted Linked List at the appropriate place in the list as determined by the comparison
// operators you will overload in the Data class. You are encouraged to reuse your code from InsertionSort project.
void SortedLinkedList::insertSorted(Data &da) {

    Node *newData = new Node(da);

    if (head == nullptr) {
        head = newData;
        //if the list is empty, no sorting necessary
        //if there is only one element in the list, it is already sorted
    } else {
        Node *current = head; //to cycle over list to find elements not sorted
        int count = 0;
        Node *previous = nullptr;
        bool sorted;

        if (current->data > newData->data) {
            newData->next = head;
            head = newData;
            return; //end the class because found where it goes
        }
        //otherwise continue searching
        previous = current;
        current = current->next;//keep iterating

        while (current) {
            if (newData->data > current->data) { //the next one is still larger so don't need to move anything around
                previous = current;
                current = current->next;
            }
        }
        //after this statement, the location is found so can insert it
        Node *temp = current;
        newData->next = current;
        previous->next = newData;

    }
}

