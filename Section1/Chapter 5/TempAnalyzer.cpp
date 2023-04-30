#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int main(){
    cout << "Temperature Analyzer\n\n";

    //open input file
    string fileName;
    ifstream inFile;
    while(true){
        cout << "Enter input filename: ";
        cin >> fileName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        inFile.open(fileName);
        if(inFile){ //if file open successfully
            break;
        } else {
            cout << "Unable to open input file! Try again.\n";
        }
    }
    cout << "Input file (" << fileName << ") opened successfully.\n\n";

    //start ouput
    cout << fixed << setprecision(2);

    //output header table
    int col = 7; //column width for display
    cout << setw(col) << "Low" << setw(col) << "High" << setw(col) << "Avg" << endl;
    cout << "---------------------------------";

    //initalize variables used in the loop
    double low = 0.0;
    double high = 0.0;
    double avg = 0.0;
    double avgTotal = 0.0;
    double lowest = 1000.0;
    double highest = -1000.0;
    int lineRead = 0;
    int linesProcessed = 0;

    //loop through each line in the input file
    string line;
    stringstream ss;
    while(getline(inFile, line)){
        ++lineRead; //increment counter variable

        ss.str(line);
        ss.clear();

        //extract temps from string stream - if OK, process
        if(ss >> low >> high){
            ++linesProcessed;

            //calcuate average temp
            avg = (low + high)/2;

            //display low, high, avg temps
            cout << setw(col) << low << setw(col) << high << setw(col) << avg << endl;

            //update intervals
            avgTotal += avg;
            if(low < lowest){
                lowest = low;
            } 
            if(high > highest){
                highest = high;
            }
        }
    }
    inFile.close();

    cout << endl
            << linesProcessed << " of "
            << lineRead << " lines successfully processed.\n\n";

    //calcuate daily average
    double avgDaily = avgTotal/linesProcessed;

    //display calculations
    int col1 = 17;
    int col2 = 7;
    cout << left << setw(col1) << "Lowest temp: "
         << right << setw(col2) << lowest << endl
         << left << setw(col1) << "Highest temp: "
         << right << setw(col2) << highest << endl
         << left << setw(col1) << "Avg daily temp: "
         << right << setw(col2) << avgDaily << endl << endl;
}