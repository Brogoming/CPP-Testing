#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

class Product{
    protected: //available to the current class or subclasses
        std::string name;
    private:
        double price;
        int discountPercent;
    public:
        Product(std::string name = "", double price = 0.0, int discountPct = 0);

        void set_price(double pPrice);
        double get_price() const;

        void set_discount_percent(int pDiscoutPercent);
        int get_discount_percent() const;

        double get_discount_amount() const;
        double get_discount_price() const;

        virtual std::string get_description() const; //nessesary for polymorphism, this allows to function to be over writen
};

#endif