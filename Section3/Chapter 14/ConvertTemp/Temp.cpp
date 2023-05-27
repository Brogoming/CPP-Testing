#include <cmath>
#include "Temp.h"

using namespace std;

Temp::Temp(){
    int fahrenheit = 32;
    int celsius = 0;
}

double Temp::get_celsius(){
    return round(celsius * 10) / 10;
}

void Temp::set_celsius(double c){
    celsius = c;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
}

double Temp::get_fahrenheit(){
    return round(fahrenheit * 10) / 10;
}

void Temp::set_fahrenheit(double f){
    fahrenheit = f;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
}