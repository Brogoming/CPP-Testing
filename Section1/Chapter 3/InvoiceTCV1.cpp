#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << "Invoice Total Calculator 1.0\n\n";

    //get sub total from user
    double subtotal;
    cout << "Enter the subtotal: ";
    cin >> subtotal;

    //determine discount percent based on subtotal
    double discountPercent;
    if(subtotal >= 200){
        discountPercent = 0.2;
    } else if(subtotal >= 100){
        discountPercent = 0.1;
    } else {
        discountPercent = 0.05;
    }

    //calculate and round results
    double discountAmount = subtotal * discountPercent;
    discountAmount = round(discountAmount * 100)/100;

    double invoiceTotal = subtotal - discountAmount;
    invoiceTotal = round(invoiceTotal * 100)/100;

    //write the results data to the console
    cout << "Discount Percent: " << discountPercent << endl
         << "Discount Amount:  " << discountAmount << endl
         << "Invoice Total:    " << invoiceTotal << endl << endl;

    cout << "Bye!\n\n";
}