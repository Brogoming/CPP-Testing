#ifndef MURACH_CONSOLE_H
#define MURACH_CONSOLE_H

#include <string>
#include <limits>

class Console{
    public:
    Console(){}; //define default constructor

    //declare static functions
    static double get_double(std::string prompt, 
        double min = std::numericLimits<double>::min(),
        double max = std::numericLimits<double>::max());
    static int get_int(std::string prompt, 
        int min = std::numericLimits<int>::min(),
        int max = std::numericLimits<int>::max());
    static char get_char(std::string prompt, 
        bool addBlankLine = true);
};

#endif