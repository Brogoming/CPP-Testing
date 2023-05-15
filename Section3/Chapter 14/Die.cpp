#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include "Die.h"

using namespace std;

Die::Die(){
    srand(time(nullptr));
    value = 1;
}

void Die::roll(){
    value = rand() % 6; //0 <= value <= 5
    ++value; //1 <= value <= 6
}

int Die::get_value() const{
    return value;
}

void Die::get_image(){
    vector<string> die1 {"_______", "|     |", "|  o  |", "|_____|"};
    vector<string> die2 {"_______", "|o    |", "|     |", "|____o|"};
    vector<string> die3 {"_______", "|o    |", "|  o  |", "|____o|"};
    vector<string> die4 {"_______", "|o   o|", "|     |", "|o___o|"};
    vector<string> die5 {"_______", "|o   o|", "|  o  |", "|o___o|"};
    vector<string> die6 {"_______", "|o   o|", "|o   o|", "|o___o|"};

    if(value == 1){
        cout << die1[0] << endl << die1[1] << endl << die1[2] << endl << die1[3] << endl;
    } else if(value == 2){
        cout << die2[0] << endl << die2[1] << endl << die2[2] << endl << die2[3] << endl;
    } else if(value == 3){
        cout << die3[0] << endl << die3[1] << endl << die3[2] << endl << die3[3] << endl;
    } else if(value == 4){
        cout << die4[0] << endl << die4[1] << endl << die4[2] << endl << die4[3] << endl;
    } else if(value == 5){
        cout << die5[0] << endl << die5[1] << endl << die5[2] << endl << die5[3] << endl;
    } else if(value == 6){
        cout << die6[0] << endl << die6[1] << endl << die6[2] << endl << die6[3] << endl;
    }
}

void Die::set_value(int tempValue){
    if(tempValue < 1){
        throw exception();
    } else if(tempValue > 6){
        throw exception();
    } else {
        value = tempValue;
    }
}