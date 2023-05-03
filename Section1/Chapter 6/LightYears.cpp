#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Light Years Calculator\n\n";

    double lightYears;
    cout << "Enter light years: ";
    cin >> lightYears;

    //define 3 constants
    const double mply = 5.879e+12; //miles per light year
    const double kply = 9.461e+12; //kilometers per light year
    const double pply = 0.306601; //parsec per light year

    //calculate miles, km, and parsecs
    double miles = lightYears * mply;
    double km = lightYears * kply;
    double parsecs = lightYears * pply;

    //display the results
    cout << endl << setprecision(8)
         << "Scientific Notation\n"
         << "Miles:             " << miles << endl
         << "Kilometers:        " << km << endl
         << "Parsecs:           " << parsecs << endl << endl;

    cout << fixed
         << "Fixed Notation\n"
         << "Miles:             " << setw(24) << miles << endl
         << "Kilometers:        " << setw(24) << km << endl
         << "Parsecs:           " << setw(24) << parsecs << endl << endl;

    cout << "Bye!\n\n";
}