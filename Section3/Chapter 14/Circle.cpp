#include <cmath> 
#include "Circle.h"

using namespace std;

Circle::Circle(double r = 0.0){
    double radius = r;
}

double Circle::get_radius(){
    return radius;
}

void Circle::set_radius(double r){
    radius = r;
}

double Circle::get_circ(){
    double circumference = 2 * radius * pi;
    return round(circumference * 10)/10;
}

double Circle::get_diameter(){
    return 2 * radius;
}

double Circle::get_area(){
    double area = pi * pow(radius, 2.0);
    return round(area * 10)/10;
}