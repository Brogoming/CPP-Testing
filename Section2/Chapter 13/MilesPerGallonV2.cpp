#include <iostream>
#include <cmath>

using namespace std;

void display_title(){
    cout << "Miles Per Gallon Calculator\n\n";
}

double calculateMPG(double miles, double gallons){
    if(miles <= 0.0){
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if (gallons <= 0.0){
        throw invalid_argument("Error! Gallons must be > 0.");
    }
    double mpg = miles /gallons;
    mpg = round(mpg *10) /10;
    return mpg;
}

int main(){
    display_title();

    double miles;
    cout << "Miles: ";
    cin >> miles;

    double gallons;
    cout << "Gallons: ";
    cin >> gallons;

    double mpg;
    try{
        mpg = calculateMPG(miles, gallons);
        cout << "Miles per Gallon: " << mpg << "\n\n";
    } catch (const invalid_argument& e){
        cout << e.what() << "\n\n";
    }
    cout << "Bye!!\n\n";
    return 0;
}