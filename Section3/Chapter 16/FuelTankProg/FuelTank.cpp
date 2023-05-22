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