#include <iostream>
#include <string>
#include <limits>
// #include "console.h"
using namespace std;

namespace console{
    //declare hepler functions
    void discard_remaining_chars();
    void handle_invalid_number();
    bool check_range(double num, double min, double max);

    //define general-purpose functions
    double get_double(string prompt, double min, double max){
        double num = 0.0;
        bool is_valid = false;
        while(!is_valid){
            cout << prompt;
            if(!(cin >> num)){
                handle_invalid_number();
            } else {
                discard_remaining_chars();
                is_valid = check_range(num, min, max);
            }
        }
        return num;
    }

    int get_int(string prompt, int min, int max){
        int num = 0;
        bool is_valid = false;
        while(!is_valid){
            cout << prompt;
            if(!(cin >> num)){
                handle_invalid_number();
            } else {
                discard_remaining_chars();
                is_valid = check_range(num, min, max);
            }
        }
        return num;
    }

    char get_char(string prompt, bool add_blank_line = true){
        char choice = 'n';
        cout << prompt;
        cin >> choice;
        if(add_blank_line){
            cout << endl;
        }
        discard_remaining_chars();
        return choice;
    }

    void discard_remaining_chars(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void handle_invalid_number(){
        cout << "Error! Invalid number. Try again.\n";
        cin.clear();
        discard_remaining_chars();
    }

    bool check_range(double num, double min, double max){
        if(num < min){
            cout << "Error! Number must be greater than " << min << ". Try again.\n";
            return false;
        } else if(num > max){
            cout << "Error! Number must be less than " << max << ". Try again.\n";
            return false;
        } else {
            return true;
        }
    }
}