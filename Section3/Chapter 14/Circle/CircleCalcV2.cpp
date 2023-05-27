#include <iostream>
#include <cmath> //need this for more math functions: sqrt, pow, round, floor, ceil
#include "Circle.cpp"

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() { 
	//print name of program
	cout << "Circle Calculator" << endl << endl;

    //circle object
    Circle circle;

	//get radius from user
	double radius;
	cout << "Enter radius: 		";
	cin >> radius;
    circle.set_radius(radius);

	//write output to console
	cout << "Diameter:		" << circle.get_diameter() << endl
		 << "Circumference: 		" << circle.get_circ() << endl
		 << "Area:			" << circle.get_area() << endl << endl
		 << "Bye!";

	//return value that indicates normal program exit
	return 0;
}