#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

class Product{
    double price;
    int discoutPercent;
public:
    std::string name;
    Product(std::string name = "", double price = 0.0, int discoutPct = 0);

    void set_price(double);
    double get_price() const {
        return price;
    }

    void set_discount_percent(int);
    int get_discount_percent() const{
        return discoutPercent;
    }

    double get_discount_amount();
    double get_discount_price();

};

#endif // MURACH_PRODUCT_H