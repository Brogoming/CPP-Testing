#include <iostream>
#include <cmath> //need this for more math functions: sqrt, pow, round, floor, ceil

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() { 
	//print name of program
	cout << "Circle Calculator" << endl << endl;

    char yorn = 'y';
    while(yorn == 'y'){
        double radius;
        cout << "Enter radius: 		";
        cin >> radius;

        if(radius <= 0){
            cout << "Radius must be a positive number.\n\n";
            continue;
        }

        //make calculations
        double pi = 3.14159;
        double diameter = 2 * radius;
        double circumference = diameter * pi;
        double area = pi * pow(radius, 2.0);

        //round to 1 decimal place
        circumference = round(circumference * 10)/10;
        area = round(area * 10)/10;

        //write output to console
        cout << "Diameter:		" << diameter << endl
            << "Circumference: 		" << circumference << endl
            << "Area:			" << area << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> yorn;
    }

    //return value that indicates normal program exit
    return 0;
}