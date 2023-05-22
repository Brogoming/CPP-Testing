#ifndef MURACH_FUEL_CAN_H
#define MURACH_FUEL_CAN_H

class FuelTank; //forward declaration of a class

class FuelCan{
    private:
        double gallons = 0;
    public:
        FuelCan(double gallonsParam = 0){
            gallons = gallonsParam;
        }
        double get_gallons(){
            return gallons;
        }
        friend void pour(FuelTank& tank, FuelCan& can);
};

#endif