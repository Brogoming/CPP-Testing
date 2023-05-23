#include <iostream>
#include "FuelTank.h"

using namespace std;

double FuelTank::get_liters() const {
    double liters = gallons * 3.7854;
    return liters;
}

void pour(FuelTank& tank, FuelCan& can){
    tank.gallons += can.gallons; //access private data member
    can.gallons = 0; //access private data member
}

FuelTank FuelTank::operator+ (const FuelTank& right){
    FuelTank t;
    t.set_gallons(gallons + right.gallons);
    return t;
}

FuelTank& FuelTank::operator++ (){
    ++gallons;
    return *this;
}

FuelTank FuelTank::operator++ (int unusedParam){
    FuelTank temp = *this; //make copy of current object
    ++*this; //increment current object
    return temp; //return the pre-increment copy
}

bool FuelTank::operator< (const FuelTank& right){
    return (gallons < right.gallons);
}

bool FuelTank::operator> (const FuelTank& right){
    return (gallons > right.gallons);
}

bool FuelTank::operator== (const FuelTank& right){
    return (gallons == right.gallons);
}

ostream& operator<< (ostream& out, const FuelTank& tank){
    out << "Gallons: " << tank.gallons << endl
        << "Liters: " << tank.get_liters() << endl << endl;
    return out;
}

istream& operator>> (istream& in, FuelTank &tank){
    cout << "Enter gallons: ";
    in >> tank.gallons;
    return in;
}