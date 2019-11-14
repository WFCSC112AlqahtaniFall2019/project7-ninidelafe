//
// Created by Nini de la Fe on 11/7/19.
//

#include "Queue.h"
using namespace std;

//default constructor
Queue::Queue() {
    tail= nullptr;
    //front = nullptr;
}

//a member public function named “enqueue_tail” takes in a Data object, creates a Node pointer, and inserts
//it into the Queue at the tail of the list.
void Queue::enqueue_tail(Data &da) {
    Node* temp = new Node(da);
    //if the list is empty
    if(head == nullptr){ //case 1: the queue is empty.
        head = temp;
        tail = temp;
    }
    //WRITE A NOTE HERE!!
    else {
        temp->next = temp;
        tail = temp;
    }
}

//a member public function named “dequeue_head” removes a Data object pointed to by the head pointer;
//returns a boolean with value true if the list is not empty, false if the list is empty.
bool Queue::dequeue_head() {
    Node* del = head;
    if(head!= nullptr){
        head = head->next;
        del->next= nullptr;
        delete del;
        return true;
    }
    else{
        return false;
    }
}

