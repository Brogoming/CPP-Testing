#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Console.cpp"
#include "Finance.cpp"

using namespace std;

int main(){
    cout << "The Future Value Calculator\n\n";

    Console c;
    Finance f;

    char choice = 'y';
    while(tolower(choice) == 'y'){
        //get input 
        cout << "Input\n";
        double monthlyInvestment = c.get_double("Monthly Investment: ", 0, 10000);
        double yearlyInterest = c.get_double("Yearly Interest Rate: ", 0, 30);
        int years = c.get_int("Years: ", 0, 100);
        cout << endl;

        //calculate future value
        double futureVal = f.calc_future_val(monthlyInvestment, yearlyInterest, years);

        //display output per year
        cout << "Output\n"
             << fixed << setprecision(2)
             << "Monthly Investment: " << monthlyInvestment << "\n"
             << fixed << setprecision(1)
             << "Yearly Interest Rate: " << yearlyInterest << "\n"
             << "Years: " << years << "\n"
             << fixed << setprecision(2)
             << "Future Value: " << futureVal << "\n\n";

        //ask the user if they want to continue
        choice = Console::get_char("Continue? (y/n): ");
    }
    cout << "Bye!\n\n";
}