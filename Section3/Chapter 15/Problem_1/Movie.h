#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Media.h"

class Movie: public Media{
    private:
        int year;
    public:
        Movie(std::string name = "", double price = 0.0, int discountPct = 0, int yearParam = 1888, std::string format = "") : Media(name, price, discountPct, format){
            year = yearParam;
        }

        void set_year(int yearParam){
            year = yearParam;
        }
        int get_year() const { return year;}

        std::string get_description() const override final{
            return name + " (" + std::to_string(year) + ") - " + format;
        }
};
#endif