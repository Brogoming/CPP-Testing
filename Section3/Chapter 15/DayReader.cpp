#include <fstream>
#include <vector>
#include "DayReader.h"
#include "DayIOError.h"

using namespace std;

DayReader::DayReader(std::string fileNameParam){
    fileName = fileNameParam;
}

vector<Day> DayReader::load_temps(){
    vector<Day> days;
    Day day;
    ifstream inputFile(fileName);
    if(inputFile){
        while (inputFile >> day.lowTemp >> day.highTemp){
            days.push_back(day);
        }
        inputFile.close();
        return days;
    }
    else {
        throw DayIOError("Unable to open file: " + fileName);
    }
}