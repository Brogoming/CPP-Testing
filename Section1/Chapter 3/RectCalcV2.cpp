#include <iostream>
#include <cmath> //need this for more math functions: sqrt, pow, round, floor, ceil

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() { 
	//print name of program
	cout << "Rectangle Calculator V2" << endl << endl;

	//get radius from user
	double height;
    double width;
	cout << "Enter height and width: ";
	cin >> height >> width;

    if(height == 0 || width == 0){
        cout << "Height and width must be greater than zero." <<endl;
        return 0;
    }
	//make calculations
	double area = height * width;

	//write output to console
	cout << "Area:                   " << area << endl << endl
		 << "Bye!";

	//return value that indicates normal program exit
	return 0;
}