#include <iostream>
#include <string> //need this to do string variables
#include <cmath> //need this for more math functions: sqrt, pow, round, floor, ceil
#include <ctime> //lets us use time()

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() { 
	string name; //declaring a string variable (a list of connected chars)
	string fullname;
	char firstInit; //an individual letter/symbole
	int age = 0; //initalizing a variable
	double averageLife = 77.28; //average life expectancy in US

	srand(time(nullptr)); //random works a little funky, we have to seed a number for our sake we seed time so the random function is a little more random
	int randomVar = rand() % 6; //gives us a range from 0 - 5, without % 6 we would get some ridiculous numbers
	int randomVar2 = rand() % 10 + 1; //gives us a range of 1 - 10

	cout << randomVar << endl; 
	cout << randomVar2 << endl << endl;

	//this section works if you tab stuff correctly
	cout << "Who are you?\t"; //console output, << stream insertion operator
	firstInit = cin.get();
	cin.ignore(100, '\n');

	cout << "Your full name?\t";
	getline(cin, fullname); //gets the full line of text that the user inputs

	cout << "How old are you?\t";
	cin >> age; //console input, >> stream extraction operator

	cout << fullname << " first inital is " << firstInit << endl;
	cout << "\t" << fullname << " is " << age << " years old!" << endl; //\t is tab
	cout << "\t" << fullname << " has about " << round(averageLife- age) << " years left!" << endl; //rounding up or down the average life expectancy - age
}