#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Media.h"

class Book : public Media{
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "", std::string format = "") : Media(name, price, discountPct, format){
            author = authorParam;
        }

        void set_author(std::string authorParam){
            author = authorParam;
        }

        std::string get_author() const {return author;}

        std::string get_description() const {
            return name + " by " + author + " - " + format;
        }
};

#endif