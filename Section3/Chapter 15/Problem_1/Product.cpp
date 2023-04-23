
#include "Product.h"

using std::string;
using std::invalid_argument;

Product::Product(string nameParam, double tempPrice, int tempDisPer){
    name = nameParam;
    set_price(tempPrice);
    set_dicount_percent(tempDisPer);
}

void Product::set_price(double pPrice){
    if(pPrice >= 0.0){
        price = round(pPrice * 100) / 100;
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

double Product::get_price() const {
    return price;
}

int Product::get_discount_percent() const {
    return discountPercent;
}

double Product::get_discount_amount() const {
    double discountAmount = price * pDiscoutPercent / 100;
    return round(discountAmount * 100) / 100;
}

double Product::get_discount_price(){
    double discountPrice = price - get_discount_amount();
    return round(discountPrice * 100) / 100;
}

string Product::get_description() const {
    return name;
}