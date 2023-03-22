#include <iostream>
#include <cmath>
#include <string>
#include "console.cpp"
#include "console.h"

using namespace std;
using namespace console;

void display_title(){
    cout << "Miles per Gallon Calculator!\n\n";
}

double calculate_mpg(double miles, double gallons){
    if(miles <= 0.0){
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if(gallons <= 0.0){
        throw invalid_argument("Error! Gallons must be > 0");
    }
    double mpg = miles/gallons;
    mpg = round(mpg * 10) / 10; //round to 1 decimal place
    return mpg;
}

int main(){
    display_title();

    double miles = 
        console::get_double("Enter miles driven:        ", 0.0, 1000000000000000);

    double gallons = 
        console::get_double("Enter gallons of gas used: ", 0.0, 1000000000000000);

    double mpg = calculate_mpg(miles, gallons);
    cout << "Miles per gallon:          " << mpg << "\n\n";
    
    cout << "Bye!\n\n";
    return 0;
}