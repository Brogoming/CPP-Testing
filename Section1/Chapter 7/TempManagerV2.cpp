#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

const string fileName = "temps.txt";

//general purpose function
char get_char(string prompt);

//functions for i/o
void load_temps(vector<double>& low, vector<double>& high);
void save_temps(const vector<double>& low, const vector<double>& high);

//functions for console i/o
void display_menu();
void view_temps(const vector<double>& low, const vector<double>& high);
void add_temps(vector<double>& low, vector<double>& high);
void remove_temps(vector<double>& low, vector<double>& high);

int main() {
	cout << "The Temperature Manager program\n\n";
	display_menu();

	//get temps from file
	vector<double> lowTemps, highTemps;
	load_temps(lowTemps, highTemps);

	char command = 'v';
	while (command != 'x') {
		//get user input
		command = get_char("Command: ");

		//execute appropriate command
		switch (tolower(command)) {
		case 'v': //shows all of the data in the file
			view_temps(lowTemps, highTemps);
			break;
		case 'a': //adds data to teh files
			add_temps(lowTemps, highTemps);
			break;
		case 'r': //removes data from the file
			remove_temps(lowTemps, highTemps);
			break;
		case 'x': //exits out of the program
			cout << "Bye\n\n";
			break;
		default: //if the user input the wrong letter
			cout << "Invalid command. Try agian.\n";
			display_menu();
			break;
		}
	}
}

char get_char(string prompt) {
	char choice;
	cout << '\n' << prompt;
	cin >> choice;

	cin.ignore(10000, '\n');
	return choice;
}

void load_temps(vector<double>& lowTemps, vector<double>& highTemps) {
	double low, high;
	ifstream inputFile(fileName);
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
}

void save_temps(const vector<double>& lowTemps, const vector<double>& highTemps) {
	ofstream outputFile(fileName);
	for (int i = 0; i < lowTemps.size(); ++i) {
		outputFile << lowTemps[i] << '\t' << highTemps[i] << '\n';
	}
	outputFile.close();
	cout << "Your changes have been saved.\n";
}

void display_menu() {
	cout << "COMMANDS\n"
		<< "v - View temperatures\n"
		<< "a - Add a temperature\n"
		<< "r - Remove temperatures\n"
		<< "x - Exit\n";
}

void view_temps(const vector<double>& lowTemps, const vector<double>& highTemps) {
	cout << "TEMPERATURES\n"
		<< setw(4) << "Day"
		<< setw(8) << "Low" << setw(8) << "High" << endl
		<< "---- -------- --------" << endl;

	cout << fixed << setprecision(1);
	int dayNum = 1;
	for (int i = 0; i < lowTemps.size(); ++i) {
		cout << left << setw(4) << dayNum
			<< right << setw(8) << lowTemps[i] << setw(8) << highTemps[i] << endl
			<< "---- -------- --------" << endl;
		++dayNum;
	}
	cout << endl;
}

void add_temps(vector<double>& lowTemps, vector<double>& highTemps) {
	double low, high;
	cout << "\nEnter low temp: ";
	cin >> low;

	cout << "\nEnter high temp: ";
	cin >> high;
	lowTemps.push_back(low);
	highTemps.push_back(high);
	save_temps(lowTemps, highTemps);
}

void remove_temps(vector<double>& lowTemps, vector<double>& highTemps) {
	int day;
	cout << "\nEnter day to remove: ";
	cin >> day;

	int index = day - 1;
	if (index >= 0 && index < highTemps.size()) {
		highTemps.erase(highTemps.begin() + index);
		lowTemps.erase(lowTemps.begin() + index);
		cout << "Temps for day " << day << " have been removed.\n";
		save_temps(lowTemps, highTemps);
	}
	else {
		cout << "Unable to remove day " << day << ". Invalid day.\n\n";
	}
}
