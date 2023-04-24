#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //print name of program
    cout << "Gallons Converter" << endl << endl;

    //get gallons from user
    double gallons;
    cout << "Enter gallons: ";
    cin >> gallons;

    //convert gallons to liters
    double liters = gallons * 3.7854;
    double quarts = gallons * 4;
    double ounces = gallons * 128;

    //rounding to 2 decimals
    liters = round(liters * 100) / 100;
    quarts = round(quarts * 100) / 100;
    ounces = round(ounces * 100) / 100;

    //write output to console
    cout << "Liters:        " << liters << endl
         << "Quarts:        " << quarts << endl
         << "Ounces:        " << ounces << endl << endl
         << "Bye!";

    //return value that indicates normal program exit
    return 0;
}