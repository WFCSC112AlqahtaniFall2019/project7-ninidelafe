//
// Created by Nini de la Fe on 11/7/19.
//

#include "Stack.h"

Stack::Stack(){

}
//a member public function named “push_head” takes in a Data object, creates a Node pointer, and inserts it into
// the Stack at the head of the list,
void Stack::push_head(Data& da){
    Node *newHead = new Node(da);
    if (head->data.getCountry()=="") {
        head = newHead;
    }
    else {
        newHead->next = head;
        head = newHead;
    }

}

//a member public function named “pop_head” removes a Data object pointed to by the head pointer; returns a boolean
// with value true if the list is not empty, false if the list is empty.
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