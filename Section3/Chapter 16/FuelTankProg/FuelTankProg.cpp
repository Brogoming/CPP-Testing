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

    FuelTank tank2(102);
    FuelTank tank3(250);
    FuelTank tank4 = tank2 + tank3;

    cout << "Tank 4" << endl
         << "Gallons: " << tank4.get_gallons() << endl
         << "Liters: " << tank4.get_liters() << endl << endl;

     FuelTank tank5(50);
     cout << "Tank 5" << endl
         << "Gallons: " << tank5++.get_gallons() << endl
         << "Gallons + 1: " << tank5.get_gallons() << endl << endl;

     if(tank1 < tank2){
          cout << "The first tank has less fuel than the second tank." << endl;
     } else if(tank1 > tank2){
          cout << "The first tank has more fuel than the second tank." << endl;
     } else if(tank1 == tank2){
          cout << "The first tank has the same fuel than the second tank." << endl;
     }
     cout << endl;

     FuelTank tank6, tank7;
     cin >> tank6 >> tank7;
     cout << endl << "Tank 6 and 7" << endl
         << tank6
         << tank7;

    return 0;
}