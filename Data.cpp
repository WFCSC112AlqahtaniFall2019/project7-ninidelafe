//
// Created by Nini de la Fe on 11/7/19.
//

#include <string>
#include <iostream>
#include "Data.h"

using namespace std;

Data::Data() {
    country = "";
    happinessRank = 0;
    happinessScore = 0.0;
    GDPperCapita = 0.0;
    lifeExpectancy = 0.0;
}

Data::Data(string c, int r, double s, double g, double l) {
    country = c;
    happinessRank = r;
    happinessScore = s;
    GDPperCapita = g;
    lifeExpectancy = l;

}

//overloads the outstream operator; but I think this is wrong; how do i get my data to make itself into a linked list?
//that should then be printed through this overload right?
//based on one found online
ostream& operator<<(ostream& os, const Data& pr) {
    os << pr.country << ": " << pr.happinessRank<< ", " << pr.happinessScore<< ", "<< pr.GDPperCapita<< ", "<< pr.lifeExpectancy;
    return os;
}

//overloads > for happiness rank
// do I need overloaded operators for every variable? or how can i make this work for any variable type?
bool Data:: operator < (Data hr){
    if (this->happinessRank > hr.happinessRank){
        return false;
    }
    else if (this->happinessRank < hr.happinessRank){
        return true;
    }
    else{
        return false;
    }
}

bool Data::operator>(Data hr) {
    return happinessRank>hr.happinessRank;
}
void Data::setCountry(string c) {
    country = c;
}
string Data:: getCountry(){
    return country;
}
void Data:: sethappinessRank (double r){
    happinessRank = r;
}
double Data:: gethappinessRank(){
    return happinessRank;
}
void Data:: sethappinessScore (double s){
    happinessScore = s;
}
double Data:: gethappinessScore(){
    return happinessScore;
}
void Data:: setGDP(double g){
    GDPperCapita = g;
}
double Data:: getGDP(){
    return GDPperCapita;
}
void Data::setLifeExpectancy(double le){
    lifeExpectancy= le;
}
double Data:: getLifeExpectancy() {
    return lifeExpectancy;
}