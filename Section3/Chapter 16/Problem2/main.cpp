#include <iostream>
#include <cmath>
#include "Circle.cpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
	// print name of program
	cout << "Circle Tester" << endl << endl;

	// create and display Circle object
	Circle circle1(20);
	cout << "CIRCLE 1:\n" << circle1 << endl;

	Circle circle2(10);
	cout << "CIRCLE 2:\n" << circle2 << endl;

	// test the addition and subtraction operators
	Circle circle3 = circle1 + circle2;
	cout << "CIRCLE 3:\n" << circle3 << endl;

	Circle circle4 = circle1 - circle2;
	cout << "CIRCLE 4:\n" << circle4 << endl;

	// test the increment operator
	++circle4;
	cout << "CIRCLE 4 after ++:\n" << circle4 << endl;
}