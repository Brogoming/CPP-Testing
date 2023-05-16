#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Media.h"

class Movie : public Media{ //inherits the Product class
    private:
        int year;
    public:
        Movie(std::string name = "", double price = 0.0, int discountPct = 0, int yearParam = 1888, std::string formatParam = "") : 
        Media(name, price, discountPct, formatParam){
            year = yearParam;
        }

        void set_year(int yearParam){
            year = yearParam;
        }
        int get_year() const { return year;}

        std::string get_description() const override{ //overrides the function
            return name + " (" + std::to_string(year) + "): " + format;
        }
};
#endif