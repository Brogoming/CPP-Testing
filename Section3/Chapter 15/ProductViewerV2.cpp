#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
// #include "Product.h"
// #include "Book.h"
// #include "Movie.h"

using namespace std;

//Product.h
class Product{
    double price;
    int discoutPercent;
public:
    string name;
    Product(string name = "", double price = 0.0, int discoutPct = 0);

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

    virtual std::string get_description() const;
};

Product::Product(string pName, double price, int discoutPercent){
    name = pName;
    set_price(price);
    set_discount_percent(discoutPercent);
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

double Product::get_discount_amount(){
    double discountAmount = price * discoutPercent / 100;
    return round(discountAmount * 100) / 100;
}

double Product::get_discount_price(){
    double discountPrice = price - get_discount_amount();
    return round(discountPrice * 100) / 100;
}

string Product::get_description() const {
    return name;
}

//Book.h
class Book : public Product{
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "") : Product(name, price, discountPct){
            author = authorParam;
        }

        void set_author(std::string authorParam){
            author = authorParam;
        }

        std::string get_author() const {return author;}

        std::string get_description() const {
            return name + " by " + author;
        }
};

//Movie.h
class Movie: public Product{
    private:
        int year;
    public:
        Movie(std::string name = "", double price = 0.0, int discountPct = 0, int yearParam = 1888) : Product(name, price, discountPct){
            year = yearParam;
        }

        void set_year(int yearParam){
            year = yearParam;
        }
        int get_year() const { return year;}

        std::string get_description() const {
            return name + " (" + std::to_string(year) + ")";
        }
};

Product p1("Stanley 13 Ounce Wood Hammer", 12.99, 62);
Book p2("The Big Short", 15.95, 34, "Micheal Lewis");
Movie p3("The Wizard of Oz", 14.99, 50, 1939);

void show_products(){
    cout << "Products\n"
        << "1. " << p1.get_description() << endl
        << "2. " << p2.get_description() << endl
        << "3. " << p3.get_description() << endl << endl;
}

void show_product(Product& p){
    cout << "Product Data\n"
        << "Name:               " << p.get_description() << endl
        << "Price:              " << p.get_price() << endl
        << "Discount Percent:   " << p.get_discount_percent() << endl
        << "Discount Amount:    " << p.get_discount_amount() << endl
        << "Discount Price:     " << p.get_discount_price() << "\n\n";
}

int main(){
    cout << "The Product Viewer program\n\n";

    show_products();

    char choice = 'y';
    while(choice == 'y'){
        int number;
        cout << "Enter product number: ";
        cin >> number;
        cout << endl;

        switch(number){
            case 1:
                show_product(p1);
                break;
            case 2:
                show_product(p2);
                break;
            case 3:
                show_product(p3);
                break;
            default:
                cout << "Invalid product number.\n\n";
                break;
        }

        cout << "View another product? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye\n\n";
    return 0;
}