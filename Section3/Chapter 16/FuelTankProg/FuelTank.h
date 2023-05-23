#ifndef MURACH_FUELTANK_H
#define MURACH_FUELTANK_H

#include "FuelCan.h"

class FuelTank{
    private:
        double gallons;
    public: 
        FuelTank(double gallonsParam = 0){
            gallons = gallonsParam;
        }
        void set_gallons(double gallonsParam){
            gallons = gallonsParam;
        }
        double get_gallons() const {
            return gallons;
        }
        double get_liters() const;
        friend void pour(FuelTank& tank, FuelCan& can);
        FuelTank operator+ (const FuelTank& right);
        FuelTank& operator++ ();
        FuelTank operator++ (int unusedParam);
        bool operator< (const FuelTank& right);
        bool operator> (const FuelTank& right);
        bool operator== (const FuelTank& right);
        friend std::ostream& operator<< (std::ostream&, const FuelTank&);
        friend std::istream& operator>> (std::istream&, FuelTank&);
};

#endif