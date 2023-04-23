#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

class Product{
    protected:
        std::string name;
    private:
        double price;
        int discountPercent;
    public:
        Product(std::string name = "", double price = 0.0, int discountPct = 0);

        void set_price(double);
        double get_price() const {return price;}

        void set_dicount_percent(int);
        int get_discount_percent() const {return discountPercent;}

        double get_discount_amount() const;
        double get_discount_price() const;

        virtual std::string get_description() const = 0;
};

#endif