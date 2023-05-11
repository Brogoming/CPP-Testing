#include <iostream>
#include <array>
#include <cmath>

using namespace std;

double calculate_total(double sales[], int salesCount);

int main(){
    const int size = 12;
    double sales[size] {0}; //set each element of the array to zero

    cout << "The Product Sales Program\n\n";

    cout << "Enter product sales from 0 to 10,000."
         << "To end the program, enter -1.\n\n";

    //initialize variables
    int salesCount = 0;
    double sale = 0.0;

    //prevent out of bounds access by making sure score count is less than array capacity
    while(sale != -1 && salesCount < size){
        cout << "Enter sales amount: ";
        cin >> sale;

        if(cin.fail()){
            cin.clear(); //clear bad input flag
            cin.ignore(1000000, '\n'); //discard input up to end of line
            cout << "Invalid number. Try again.\n";
        } else if(sale > 10000){
            cout << "score must be between 0 and 10000. Try again.\n";
        } else if(sale < -1){
            cout << "Score can't be a negative number. Try again.\n";
        } else if(sale > -1){
            sales[salesCount] = sale; //store score in array
            ++salesCount;
        }
    }
    cout << endl;

    if(salesCount == 0){
        cout << "No sales entered.\n\n";
    } else {
        //calculate total average scores
        double total = calculate_total(sales, salesCount);
        double average = total / salesCount;
        average = round(average*10)/10;

        //display the score count, score total, and average score
        cout << "Sales count:     " << salesCount << endl
             << "Sales total:     " << total << endl
             << "Average Sales:   " << average << endl << endl;
    }

    return 0;
}

double calculate_total(double sales[], int salesCount){
    double total = 0.0;
    for(int i = 0; i < salesCount; ++i){
        total += sales[i];
    }
    return total;
}