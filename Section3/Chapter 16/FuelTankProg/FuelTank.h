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
};

#endif