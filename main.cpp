#include <iostream>
#include <fstream>
#include "Data.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"


using namespace std;
int main() {

    Data other;
    Stack* topToBottom = new Stack;
    Queue* line = new Queue;
    SortedLinkedList* sortedList = new SortedLinkedList;

    ifstream in;
    ofstream outStack;
    ofstream outQueue;
    ofstream outSorted;

    in.open ("World Happiness Report 2015.csv");
    outStack.open("Stack.txt");
    outQueue.open("Queue.txt");
    outSorted.open("Sorted.txt");

    if(!in.is_open()){
        cout<<"Input file did not open!!"<<endl;
        return 1;
    }
    if(!outStack.is_open()){
        cout<<"Stack output file did not open!!"<<endl;
        return 2;
    }
    if(!outQueue.is_open()){
        cout<<"Queue output file did not open!!"<<endl;
        return 3;
    }
    if(!outSorted.is_open()){
        cout<<"Sorted output file did not open!!"<<endl;
        return 4;
    }

    while (!in.eof()) {

        //getline will go until the comma then will move on
        string crty, haprate, hapscor, GDP, lifeExpec;
        getline(in, crty, ',');
        getline(in, haprate, ',');
        getline(in, hapscor, ',');
        getline(in, GDP, ',');
        getline(in, lifeExpec, '\n');


        int rating = stoi(haprate); //change into integer
        double score = stod(hapscor); //change into a double
        double gdp = stod(GDP); //change into a double
        double life = stod(lifeExpec);

        Data info = Data (crty, rating, score, gdp, life); //creating the Data object with the information
        topToBottom->push_head(info); //putting the information in the stack
        line->enqueue_tail(info); //putting the information in the queue
        sortedList->insertSorted(info); //putting the information in the linkedlist
        other=info;
    }

    topToBottom->print(outStack);
    line->print(outQueue);
    sortedList->print(outSorted);

    while (topToBottom->pop_head(other));
    while (line->dequeue_head());

    in.close();
    outQueue.close();
    outSorted.close();
    outStack.close();
    cout<<"Files are closed!"<<endl;


    return 0;
}