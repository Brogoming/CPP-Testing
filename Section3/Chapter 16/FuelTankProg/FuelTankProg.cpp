#include <iostream>
#include "FuelCan.h"
#include "FuelTank.cpp"

using namespace std;

int main(){
    FuelTank tank1(100);
    FuelCan can1(2);
    pour(tank1, can1);

    cout << "Tank 1" << endl
         << "Gallons: " << tank1.get_gallons() << endl
         << "Liters: " << tank1.get_liters() << endl << endl;

    FuelTank tank2(100);
    FuelTank tank3(250);
    FuelTank tank4 = tank2 + tank3;

    cout << "Tank 4" << endl
         << "Gallons: " << tank4.get_gallons() << endl
         << "Liters: " << tank4.get_liters() << endl << endl;

    return 0;
}