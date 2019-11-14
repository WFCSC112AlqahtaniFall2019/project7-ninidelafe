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

    } else {
        Node *current = head;
        int count = 0;
        Node *previous = nullptr;
        bool sorted;

        if (current->data > newData->data) {
            newData->next = head;
            head = newData;
            return;
        }
        //or keeps searching
        previous = current;
        current = current->next;//keep iterating

        while (current) {
            if (newData->data > current->data) {
                previous = current;
                current = current->next;
            }
        }
        Node *temp = current;
        newData->next = current;
        previous->next = newData;

    }
}

