#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << "Invoice Total Calculator 2.0\n\n";

    //get customer type
    char customerType;
    cout << "Enter customer type (r/w/c): ";
    cin >> customerType;

    //get sub total from user
    double subtotal;
    cout << "Enter the subtotal:          ";
    cin >> subtotal;

    //determine discount percent based on subtotal
    double discountPercent;
    switch(customerType){
        case 'r':
        case 'R':
            if(subtotal < 100){
                discountPercent = 0;
            } else if(subtotal >= 100 && subtotal < 250){
                discountPercent = 0.1;
            } else if(subtotal >= 250 && subtotal < 500){
                discountPercent = 0.2;
            } else {
                discountPercent = 0.3;
            }
            break;
        case 'w':
        case 'W':
            if(subtotal < 500){
                discountPercent = 0.4;
            } else {
                discountPercent = 0.5;
            }
            break;
        case 'c':
        case 'C':
            discountPercent = 0.25;
            break;
        default:
            discountPercent = 0;
            break;
    }

    //calculate and round results
    double discountAmount = subtotal * discountPercent;
    discountAmount = round(discountAmount * 100)/100;

    double invoiceTotal = subtotal - discountAmount;
    invoiceTotal = round(invoiceTotal * 100)/100;

    //write the results data to the console
    cout << "Discount Percent:            " << discountPercent << endl
         << "Discount Amount:             " << discountAmount << endl
         << "Invoice Total:               " << invoiceTotal << endl << endl;

    cout << "Bye!\n\n";
}