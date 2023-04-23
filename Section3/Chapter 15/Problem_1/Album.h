#ifndef MURACH_ALBUM_H
#define MURACH_ALBUM_H

#include <string>
#include "Media.h"

class Album : public Media{
    private:
        std::string artist;
    public:
        Album(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "", std::string format = "") : Media(name, price, discountPct, format){
            artist = artistParam;
        }

        void set_author(std::string artistParam){
            artist = artistParam;
        }

        std::string get_author() const {return artist;}

        std::string get_description() const {
            return name + " by " + artist + " - " + format;
        }
};

#endif