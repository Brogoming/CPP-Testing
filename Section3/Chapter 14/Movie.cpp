#include "Movie.h"
#include <string>

using std::string;
using std::invalid_argument;

//private function
string Movie::to_upper(string str){
    string strUpper;
    for(char c : str){
        strUpper.push_back(toupper(c));
    }
    return strUpper;
}

//public functions
//constructor
Movie::Movie(string title, int year, int stars){
    set_title(title);
    set_year(year);
    set_stars(stars);
}

void Movie::set_title(string titleParam){
    if(titleParam.size() > 120){
        throw invalid_argument("Title must not have more than 120 characters.");
    }
    title = titleParam;
}

string Movie::get_title() const{
    return title;
}

void Movie::set_year(int yearParam){
    if(yearParam < 1888){
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = yearParam;
}

int Movie::get_year(){
    return year;
}

void Movie::set_stars(int starsParam){
    if(starsParam < 1 || starsParam > 5){
        throw invalid_argument("Stars must be from 1 to 5.");
    }
    stars = starsParam;
}

int Movie::get_stars() const{
    return stars;
}

bool Movie::iequals(const Movie& toCompare){
    return (to_upper(title) == to_upper(toCompare.title) && year == toCompare.year);
}