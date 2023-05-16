#ifndef MURACH_ALBUM_H
#define MURACH_ALBUM_H

#include <string>
#include "Media.h"

class Album : public Media{ //Book inherits the Product class
    private:
        std::string artist;
    public:
        Album(std::string name = "", double price = 0.0, int discountPct = 0, std::string artistParam = "", std::string formatParam = "") : //defines the subclass constructor using the superclass constructor
        Media(name, price, discountPct, formatParam){
            artist = artistParam;
        }

        void set_author(std::string artistParam){
            artist = artistParam;
        }

        std::string get_artist() const {return artist;}

        std::string get_description() const override{ //override function
            return name + " by " + artist + ": " + format;
        }
};

#endif //MURACH_ALBUM_H