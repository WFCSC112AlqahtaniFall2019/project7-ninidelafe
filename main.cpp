#include <iostream>
#include <fstream>
#include "Data.h"
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

    in.open ("../WorldHappiness2015.csv");
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

    cout<<"All files are opened!"<<endl<< "../WorldHappiness2015.csv is being read"<<endl;

    //int i =0;

    outQueue<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;
    outStack<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;
    outSorted<<"This list is sorted by GDP per Capita"<<endl;
    outSorted<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;


    while (!in.eof()) {
        //i++;
        //cout<<"In while loop! i= "<< i; //<< endl;
        //getline will go until the comma then will move on
        string crty, haprate, hapscor, GDP, lifeExpec;
        getline(in, crty, ',');
        getline(in, haprate, ',');
        getline(in, hapscor, ',');
        getline(in, GDP, ',');
        getline(in, lifeExpec,'\n');


        //changes from string to double
        double rating = stod(haprate);
        double score = stod(hapscor);
        double gdp = stod(GDP);
        double life = stod(lifeExpec);


        Data info = Data (crty, rating, score, gdp, life); //creates a Data object and inputs them as parameters
        topToBottom->push_head(info); //puts info into the stack
        line->enqueue_tail(info); //puts info in the queue
        //cout<<" country= "<< crty<<endl;
        sortedList->insertSorted(info); //putting the information in the linkedlist
        other=info;
    }

    cout<<"Writing data in stack inserted at head into Stack.txt"<<endl;
    cout<<"Writing data in queue inserted at tail into Queue.txt"<<endl;
    cout<<"Writing data in sorted linked list sorted by attribute into Sorted.txt"<<endl;

    topToBottom->print(outStack,other);
    line->print(outQueue,other);
    sortedList->print(outSorted,other);

    while (topToBottom->pop_head(other));
    while (line->dequeue_head());

    in.close();
    outQueue.close();
    outSorted.close();
    outStack.close();
    cout<<"All files are closed!"<<endl;


    return 0;
}