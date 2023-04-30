#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

int main(){
    cout << "Invoice Total Calculator 3.0\n\n";

    //get customer type
    char customerType;
    while(true){
        cout << "Enter customer type (r/w): ";
        cin >> customerType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(tolower(customerType) == 'r' || tolower(customerType) == 'w'){
            break;
        } else {
            cout << "Invalid customer type! Please try again.\n";
        }
    }

    //get sub total from user
    double subtotal;
    while(true){
        cout << "Enter the subtotal: ";
        cin >> subtotal;

        if(cin.good()){ //stream good - end loop
            break;
        } else if(cin.fail()){ //stream ok - try again
            cout << "Invalid number! Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(cin.bad()){ //stream bad - exit program
            cout << "Sorry, an unexpected error has occured. Bye!";
            return 0;
        }
    }

    //determine discount percent based on subtotal
    double discountPercent;
    if(tolower(customerType) == 'r'){ //retail
        if(subtotal < 100){
            discountPercent = 0;
        } else if(subtotal >= 100 && subtotal < 250){
            discountPercent = 0.1;
        } else {
            discountPercent = 0.2;
        }
    } else if(tolower(customerType) == 'w'){ //wholesale
        if(subtotal < 500){
            discountPercent = 0.4;
        } else {
            discountPercent = 0.5;
        }
    } else { //other
        discountPercent = 0.0;
    }

    //calculate and round results
    double discountAmount = subtotal * discountPercent;
    discountAmount = round(discountAmount * 100)/100;

    double invoiceTotal = subtotal - discountAmount;
    invoiceTotal = round(invoiceTotal * 100)/100;

    //write the results data to the console
    //display results
    int col1 = 18;
    int col2 = 8;
    cout << fixed << setprecision(2) << endl //2 decimal places
         << "INVOICE" << endl
         << left << setw(col1) << "Subtotal:"
         << right << setw(col2) << subtotal << endl
         << left << setw(col1) << "Discount Percent:"
         << right << setw(col2) << discountPercent << endl
         << left << setw(col1) << "Discount Amount:"
         << right << setw(col2) << discountAmount << endl
         << left << setw(col1) << "Invoice Total:"
         << right << setw(col2) << invoiceTotal << endl;

    cout << endl << left << "Bye!\n\n";
}