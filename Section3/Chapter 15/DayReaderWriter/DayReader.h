#ifndef MURACH_DAYREADER_H
#define MURACH_DAYREADER_H

#include <string>
#include <vector>
#include "Day.h" //include day structure

class DayReader {
    private:
        std::string fileName;
    public:
        DayReader(std::string fileName = "");
        std::vector<Day> load_temps();
};

#endif