//
// Created by Nini de la Fe on 11/7/19.
//

#include "Stack.h"

//creates a default constructor
Stack::Stack(){
  head= nullptr;
}

//takes in an object from Data and creates a node and inserts it on the top of the stack.
void Stack::push_head(Data& da){
    Node *newHead = new Node(da);
    //if the list is empty
    if (head == nullptr) {
        head = newHead;
    }
    //if there is already something on the list it adds it to the top
    else {
        newHead->next = head;
        head = newHead;
    }

}

//a member public function named “pop_head” removes a Data object pointed to by the head pointer; returns a boolean
// with value true if the list is not empty, false if the list is empty.

//removes
bool Stack::pop_head(Data& da) {
    if (head==nullptr){
        //cout<<"Empty List"<<endl;
        return false;
    } else{
        Node* previous;
        previous= head;
        head=head->next;
        previous->next= nullptr;
        delete previous;
        return true;
    }

}