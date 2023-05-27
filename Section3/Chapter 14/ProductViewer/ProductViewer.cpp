#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include "Product.cpp"

using namespace std;

void show_products(const vector<Product>& products){
    cout << "Products\n";
    int number = 0;
    for(Product product: products){
        cout << ++number << ". " << product.name << endl;
    }
    cout << endl;
}

void show_product(Product& p){
    cout << "Product Data\n"
        << "Name:             " << p.name << endl
        << "Price:            " << p.get_price() << endl
        << "Discount percent: " << p.get_discount_percent() << endl
        << "Discount amount:  " << p.get_discount_amount() << endl
        << "Discount price:   " << p.get_discount_price() << "\n\n";
}

int main(){
    cout << "The Product Viewer program\n\n";

    vector<Product> products;
    products.push_back(Product("Stanley 13 Ounce Wood Hammer", 12.99, 62));
    products.push_back(Product("Grape Jelly", 10.99, 0));
    products.push_back(Product("God of War", 59.99, 33));

    show_products(products);

    char choice = 'y';
    while(choice == 'y'){
        int number;
        cout << "Enter product number: ";
        cin >> number;
        cout << endl;

        if(number > 0 && number <= products.size()){
            Product product = products[number - 1];
            show_product(product);
        } else {
            cout << "There are no product with that number.\n\n";
        }

        cout << "View another product? (y/n): ";
        cin >> choice;
        cout << endl;
    }
    cout << "Bye!\n\n";
}