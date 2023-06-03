#include <iostream>
#include <string>
#include <vector>
#include "Product.cpp"
#include "Book.h"
#include "Movie.h"

using namespace std;

Product* p1 = new Product("Stanley 13 Ounce Wood Hammer", 12.99, 62);
Book* p2 = new Book("The Big Short", 15.95, 34, "Micheal Lewis");
Movie* p3 = new Movie("The Wizard of Oz", 14.99, 50, 1939);

void show_products(const vector<Product*>& products){
    int number = 0;
    for(int i = 0; i < products.size(); ++i){
        Product *p = products[i];
        cout << ++number << ". " << p->get_description() << endl;
    }
    cout << endl;
}

void show_product(const Product* p){
    cout << "Name: " << p->get_description() << endl
         << "Price: " << p->get_price() << endl
         << "Discount percent: " << p->get_discount_percent() << endl;
}

int main(){
    cout << "The Product Viewer program\n\n";

    vector<Product*> products = vector<Product*>();
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);

    show_products(products);

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