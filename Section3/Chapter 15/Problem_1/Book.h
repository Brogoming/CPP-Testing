#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Media.h"

class Book : public Media{ //Book inherits the Product class
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "", std::string formatParam = "") : //defines the subclass constructor using the superclass constructor
        Media(name, price, discountPct, formatParam){
            author = authorParam;
        }

        void set_author(std::string authorParam){
            author = authorParam;
        }

        std::string get_author() const {return author;}

        std::string get_description() const override{ //override function
            return name + " by " + author + ": " + format;
        }
};

#endif