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

    virtual std::string get_description() const = 0;
};

//Product.cpp
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

string Product::get_description() const{
    return name;
}

//Media.h
class Media: public Product {
protected:
    std::string format;
public:
    Media(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string format_param = "") : Product(name, price, disc_pct) {
        format = format_param;
    }
};

//Book.h
class Book : public Media{
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int discountPct = 0, std::string authorParam = "", std::string format = "") : Media(name, price, discountPct, format){
            author = authorParam;
        }

        void set_author(std::string authorParam){
            author = authorParam;
        }

        std::string get_author() const {return author;}

        std::string get_description() const override{
            return name + " by " + author + " - " + format;
        }
};

//UsedBook.h
class UsedBook : public Book {
public:
    UsedBook(std::string name = "", double price = 0.0,
        int disc_pct = 0, std::string author_param = "", std::string format = "") :
        Book(name, price, disc_pct, author_param, format) {
        // no code in constructor
    }

    std::string get_description() const {
        return name + " by " + Book::get_author() + " - " + format + " (Used)";
    }
};

//Movie.h
class Movie: public Media{
    private:
        int year;
    public:
        Movie(std::string name = "", double price = 0.0, int discountPct = 0, int yearParam = 1888, std::string format = "") : Media(name, price, discountPct, format){
            year = yearParam;
        }

        void set_year(int yearParam){
            year = yearParam;
        }
        int get_year() const { return year;}

        std::string get_description() const {
            return name + " (" + std::to_string(year) + ") - " + format;
        }
};

//Album.h
class Album : public Media{
    private:
        std::string artist;
    public:
        Album(std::string name = "", double price = 0.0, int discountPct = 0, std::string artistParam = "", std::string format = "") : Media(name, price, discountPct, format){
            artist = artistParam;
        }

        void set_author(std::string artistParam){
            artist = artistParam;
        }

        std::string get_author() const {return artist;}

        std::string get_description() const override final{
            return name + " by " + artist + " - " + format;
        }
};

// Product p1("Stanley 13 Ounce Wood Hammer", 12.99, 62);
Book p1("The Big Short", 15.95, 34, "Micheal Lewis", "PaperBack");
Movie p2("The Wizard of Oz", 14.99, 50, 1939, "Stream HD");
Album p3("Rubber Soul", 9.99, 10, "The Beatles", "CD");
UsedBook p4("The Big Short", 15.95, 34, "Micheal Lewis", "PaperBack");

void show_products(){
    cout << "Products\n"
        << "1. " << p1.get_description() << endl
        << "2. " << p2.get_description() << endl 
        << "3. " << p3.get_description() << endl 
        << "4. " << p3.get_description() << endl << endl;
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
            case 4:
                show_product(p4);
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