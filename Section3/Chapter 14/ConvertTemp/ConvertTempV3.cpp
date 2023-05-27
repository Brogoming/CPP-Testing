#include <iostream>
#include "Temp.cpp"

using namespace std;

//define functions
void display_menu();
void convert_temp();

int main(){
    cout << "Convert Temperatures\n\n";

    display_menu();
    char again = 'y';
    while (again == 'y'){
        convert_temp();

        cout << "Convert another temperature? (y/n): ";
        cin >> again;
        cout << endl;
    }
    cout << "Bye!\n";
}

void display_menu(){
    cout << "Menu\n"
         << "1. Fahrenheit to Celsius\n"
         << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp(){
    Temp temp;
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    switch(option){
        case 1: 
            double f;
            cout << "Enter degrees Fahrenheit: ";
            cin >> f;

            temp.set_fahrenheit(f);
            cout << "Degrees Celsius: " << temp.get_celsius() << endl;
            break;
        case 2: 
            double c;
            cout << "Enter degrees Celsius: ";
            cin >> c;

            temp.set_celsius(c);
            cout << "Degrees Fahrenheit: " << temp.get_fahrenheit() << endl;
            break;
        default:
            cout << "Must enter a valid number.\n";
            break;
    }
}
