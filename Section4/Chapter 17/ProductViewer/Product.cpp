#include <cmath>
#include "Product.h"

using std::string;
using std::invalid_argument;

Product::Product(string nameParam, double tempPrice, int tempDisPer){
    name = nameParam;
    set_price(tempPrice);
    set_discount_percent(tempDisPer);
}

void Product::set_price(double pPrice){
    if(pPrice >= 0.0){
        price = round(pPrice * 100) / 100;
    } else {
        throw invalid_argument("Price can't be negative.");
    }
}

void Product::set_discount_percent(int pDiscountPercent){
    if(pDiscountPercent >= 0 && pDiscountPercent <= 100){
        discountPercent = pDiscountPercent;
    } else {
        throw invalid_argument("Price can't be negative.");
    }
}

double Product::get_price() const {
    return price;
}

int Product::get_discount_percent() const {
    return discountPercent;
}

double Product::get_discount_amount() const {
    double discountAmount = price * discountPercent / 100;
    return round(discountAmount * 100) / 100;
}

double Product::get_discount_price() const{
    double discountPrice = price - get_discount_amount();
    return round(discountPrice * 100) / 100;
}

string Product::get_description() const {
    return name;
}