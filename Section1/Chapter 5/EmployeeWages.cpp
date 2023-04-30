#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("wages.txt");

    //start ouput
    cout << fixed << setprecision(2);

    //output header table
    int col = 12; //column width for display
    cout << left << setw(col) << "Name" << right << setw(col) << "Hourly Wage" << right << setw(col) << "Hours" << right << setw(col) << "Total" << endl;
    cout << "------------------------------------------------" << endl;

    string name;
    double hourlyWage;
    double hours;
    int lineRead = 0;
    int linesProcessed = 0;

    //loop through each line in the input file
    string line;
    stringstream ss;
	if (infile) {
        while(getline(infile, line)){
            ++lineRead; //increment counter variable

            ss.str(line);
            ss.clear();

            //extract temps from string stream - if OK, process
            if(ss >> name >> hourlyWage >> hours){
                ++linesProcessed;

                cout << left << setw(col) << name << right << setw(col) << hourlyWage << right << setw(col) << hours << right << setw(col) << hourlyWage * hours << endl;
            }
        }
		infile.close();
        cout << endl
            << linesProcessed << " of "
            << lineRead << " lines successfully processed.\n\n";

	} else {
        cout << "Unable to open file";
    }
}

