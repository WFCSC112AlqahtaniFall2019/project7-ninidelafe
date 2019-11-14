//
// Created by Nini de la Fe on 11/7/19.
//

#include <string>
#include <iostream>
#include "Data.h"

using namespace std;

//creates a default constructor for the data
Data::Data() {
    country = "";
    happinessRank = 0.0;
    happinessScore = 0.0;
    GDPperCapita = 0.0;
    lifeExpectancy = 0.0;
}
//creates an alternate constructor for when the data is inputted through parameters
Data::Data(string c, double r, double s, double g, double l) {
    country = c;
    happinessRank = r;
    happinessScore = s;
    GDPperCapita = g;
    lifeExpectancy = l;

}

//overloads the outstream operator
ostream& operator<<(ostream& os, const Data& pr) {
    os << pr.country << ": " << pr.happinessRank<< ", " << pr.happinessScore<< "," << pr.GDPperCapita << ", "<< pr.lifeExpectancy;
    return os;
}

//overloads < operator for happiness rank? maybe GDPperCapita
bool Data:: operator < (Data& hr){
    //return this->GDPperCapita < hr.GDPperCapita;
    if (this->GDPperCapita > hr.GDPperCapita){
        return false;
    }
    else if (this->GDPperCapita < hr.GDPperCapita){
        return true;
    }
    else{
        return false;
    }
}


bool Data::operator>=(Data& hr) {
    return this->GDPperCapita>hr.GDPperCapita;
}

bool Data::operator>(Data& hr) {
    return this->GDPperCapita>hr.GDPperCapita;
}


/*//Dont know if i need these or not
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
}*/