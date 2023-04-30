#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() {

	string filename = "temps.txt";
	char command = 'v';

	cout << "The Temperature Manager program\n\n";

	cout << "COMMANDS\n" << "v - View temperatures\n" << "a - Add a temperature\n" << "x - Exit\n";

	while (command != 'x') {
		cout << endl;
		cout << "Command: ";
		cin >> command;
		cout << endl;
		if (command == 'v') {
			cout << "TEMPERATURES\n";
			cout << setw(8) << "Low" << setw(8) << "High" << endl;

			ifstream input_file;
			input_file.open(filename); //opens the file

			double low;
			double high;
			if (input_file) { //if the file exists
				cout << fixed << setprecision(1);
				while (input_file >> low >> high) //read line from the file
					cout << setw(8) << low << setw(8) << high << endl; //output the line
				input_file.close(); //close the file
			}
			else {
				cout << "Unable to open file";
			}
		}
		else if (command == 'a') {
			double low;
			double high;

			cout << "Enter low temp: ";
			cin >> low;

			cout << "Enter high temp: ";
			cin >> high;


			//write to the file
			ofstream output_file;
			output_file.open(filename, ios::app); //appends to the file
			output_file << fixed << setprecision(1);
			output_file << low << '\t' << high << '\n'; //inputs into the file
			output_file.close(); //closes the file
			cout << "Temps have been saved.\n";
		}
		else if (command == 'x') {
			cout << "Bye!\n\n";
		} 
		else {
			cout << "Invalid command. Try again.\n";
		}
	}
	
}