#include <string>
#include <cmath>
#include "Product.h"

using std::string;
using std::invalid_argument;

Product::Product(string pName, double price, int discoutPercent){
    name = pName;
    set_price(price);
    set_discount_percent(discoutPercent);
}

void Product::set_price(double pPrice){
    if(price >= 0.0){
        price = round(price * 100) / 100;
    } else {
        throw invalid_argument("Price can't be negative.");
    }
}

void Product::set_discount_percent(int pDiscoutPercent){
    if(pDiscoutPercent >= 0.0 && pDiscoutPercent <= 100){
        discoutPercent = pDiscoutPercent;
    } else {
        throw invalid_argument("Price can't be negative.");
    }
}

double Product::get_discount_amount(){
    double discountAmount = price * pDiscoutPercent / 100;
    return round(discountAmount * 100) / 100;
}

double Product::get_discount_price(){
    double discountPrice = price - get_discount_amount();
    return round(discountPrice * 100) / 100;
}