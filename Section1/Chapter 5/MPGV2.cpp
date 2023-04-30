#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";
    ifstream inputFile;
    inputFile.open("trips.txt");
    double fileMiles = 0;
    double fileGallons = 0;
    double totalMiles = 0;
    double totalGallons = 0;
    if (inputFile) { //if the file exists
        cout << right << setw(12) << "Miles" << right << setw(12) << "Gallons" << right << setw(12) << "MPG" << endl;
        cout << fixed << setprecision(2);
        while (inputFile >> fileMiles >> fileGallons){ //read line from the file
            cout << setw(12) << fileMiles << setw(12) << fileGallons << setw(12) << fileMiles/fileGallons << endl; //output the line
            totalMiles += fileMiles;
            totalGallons += fileGallons;
        }
        cout << endl << "Total miles:       " << totalMiles << endl;
        cout << "Total gallons      " << totalGallons << endl;
        cout << "Average MPG:       " << totalMiles/totalGallons << endl;

        inputFile.close(); //close the file
    }
    else {
        cout << "Unable to open file";
    }

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		// get miles driven
		double miles = 0;
		while (true) {
			cout << endl << "Enter miles driven:        ";
			cin >> miles;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(cin.fail()){
                cout << "That's not a valid number. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

			// check the range of the number
			if (miles <= 0) {
				cout << "Miles driven must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

		// get gallons of gas used
		double gallons = 0;
		while (true) {
			cout << "Enter gallons of gas used: ";
			cin >> gallons;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(cin.fail()){
                cout << "That's not a valid number. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

			// check the range of the number
			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
		}

        ofstream outputFile;
        outputFile.open("trips.txt", ios::app); //appends to the file
        outputFile << fixed << setprecision(1);
        outputFile << miles << '\t' << gallons << '\n'; //inputs into the file
        outputFile.close(); //closes the file

		// calculate miles per gallon
		double mpg = miles / gallons;
		mpg = round(mpg * 100) / 100;
		cout << "Miles per gallon:          " << mpg << endl << endl;

        inputFile.open("trips.txt");
        double fileMiles = 0;
        double fileGallons = 0;
        double totalMiles = 0;
        double totalGallons = 0;
        if (inputFile) { //if the file exists
            cout << right << setw(12) << "Miles" << right << setw(12) << "Gallons" << right << setw(12) << "MPG" << endl;
            cout << fixed << setprecision(2);
            while (inputFile >> fileMiles >> fileGallons){ //read line from the file
                cout << setw(12) << fileMiles << setw(12) << fileGallons << setw(12) << fileMiles/fileGallons << endl; //output the line
                totalMiles += fileMiles;
                totalGallons += fileGallons;
            }
            cout << endl << "Total miles:       " << totalMiles << endl;
            cout << "Total gallons      " << totalGallons << endl;
            cout << "Average MPG:       " << totalMiles/totalGallons << endl;

            inputFile.close(); //close the file
        }
        else {
            cout << "Unable to open file";
        }

		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
        cout << endl;
	}

	cout << "Bye!\n\n";
}