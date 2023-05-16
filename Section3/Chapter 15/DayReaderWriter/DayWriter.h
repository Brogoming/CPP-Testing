#ifndef MURACH_DAYWRITER_H
#define MURACH_DAYWRITER_H

#include <string>
#include <vector>
#include "Day.h" //include day structure

class DayWriter{
    private:
    std::string fileName;
    public:
    DayWriter(std::string fileName = "");
    void save_temp(const std::vector<Day>& temps);
};

#endif