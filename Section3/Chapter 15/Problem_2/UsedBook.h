#ifndef MURACH_USEDBOOK_H
#define MURACH_USEDBOOK_H

#include <string>
#include "Book.h"

class UsedBook : public Book{ //Book inherits the Product class
    public:
        UsedBook(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "", std::string formatParam = "") : //defines the subclass constructor using the superclass constructor
        Book(name, price, discountPct, authorParam, formatParam){}

        std::string get_description() const override final{ //override function
            return name + " by " + get_author() + ": " + format + " (Used)";
        }
};

#endif //MURACH_USEDBOOK_H