#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Product.h"

class Book : public Product{ //Book inherits the Product class
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "") : //defines the subclass constructor using the superclass constructor
            Product(name, price, discountPct){
            author = authorParam;
        }

        void set_author(std::string authorParam){
            author = authorParam;
        }

        std::string get_author() const {return author;}

        std::string get_description() const override{ //override function
            return name + " by " + author;
        }
};

#endif