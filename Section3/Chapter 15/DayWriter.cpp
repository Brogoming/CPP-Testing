#include <fstream>
#include <vector>
#include "DayWriter.h"

using namespace std;

DayWriter::DayWriter(std::string fileNameParam){
    fileName = fileNameParam;
}

void DayWriter::save_temp(const vector<Day>& days){
    ofstream outputFile(fileName);
    for(Day day : days){
        outputFile << day.lowTemp << '\t' << day.highTemp << '\n';
    }
    outputFile.close();
}