#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Product.h"

class Movie : public Product{ //inherits the Product class
    private:
        int year;
    public:
        Movie(std::string name = "", double price = 0.0, int discountPct = 0, int yearParam = 1888) : 
            Product(name, price, discountPct){
            year = yearParam;
        }

        void set_year(int yearParam){
            year = yearParam;
        }
        int get_year() const { return year;}

        std::string get_description() const override{ //overrides the function
            return name + " (" + std::to_string(year) + ")";
        }
};
#endif