#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std; //makes it easier to code with using std::, we can specify what keywords can use namespace but I rather have this globally for everything

int main() {

	//state the variables
	string fileName = "temps.txt";
	char command = 'v';
	double low, high;
	vector<double> lowTemps, highTemps;
	ifstream inputFile;
	ofstream outputFile;
	int dayNum, index;

	cout << "The Temperature Manager program\n\n";
	cout << "COMMANDS\n"
		<< "v - View temperatures\n"
		<< "a - Add a temperature\n"
		<< "r - Remove temperatures\n"
		<< "s - Save changes\n"
		<< "x - Exit\n";

	//if the file is created input the data into the lists
	inputFile.open(fileName);
	if (inputFile) {
		while (inputFile >> low >> high) {
			lowTemps.push_back(low);
			highTemps.push_back(high);
		}
		inputFile.close();
	}
	else {
		cout << "\nUnable to open file. You may need to add temperatures.\n";
	}

	while (command != 'x') {
		//get user input
		cout << endl;
		cout << "Command: ";
		cin >> command;
		cout << endl;

		//execute appropriate command
		switch (command) {
		case 'v': //shows all of the data in the file
			cout << "TEMPERATURES\n" 
				<< setw(4) << "Day" 
				<< setw(8) << "Low" << setw(8) << "High" << endl 
				<< "---- ------- -------" << endl;

			cout << fixed << setprecision(1);
			dayNum = 1;
			for(int i = 0; i < lowTemps.size(); ++i){
				low = lowTemps[i];
				high = highTemps[i];
				cout << left << setw(4) << dayNum
					 << right << setw(8) << low << setw(8) << high << endl
					 << "---- ------- -------" << endl;
				++dayNum;
			}
			break;
		case 'a': //adds data to teh files
			cout << "Enter low temp: ";
			cin >> low;

			cout << "Enter high temp: ";
			cin >> high;
			lowTemps.push_back(low);
			highTemps.push_back(high);
			break;
		case 'r': //removes data from the file
			int day;
			cout << "Enter day to remove: ";
			cin >> day;

			index = day - 1;
			if (index >= 0 && index < highTemps.size()) {
				highTemps.erase(highTemps.begin() + index);
				lowTemps.erase(lowTemps.begin() + index);
			}

			cout << "Temps for day " << day << " have been removed.\n";
			break;
		case 's': //saves everything that has been changed
			outputFile.open(fileName);
			for (int i = 0; i < lowTemps.size(); ++i) {
				low = lowTemps[i];
				high = highTemps[i];
				outputFile << low << '\t' << high << '\n';
			}
			outputFile.close();
			cout << "Your changes have been saved.\n";
			break;
		case 'x': //exits out of the program
			cout << "Bye\n\n";
			break;
		default: //if the user input the wrong letter
			cout << "Invalid command. Try agian.\n";
			break;
		}
	}
}