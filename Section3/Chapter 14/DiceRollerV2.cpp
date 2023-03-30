#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
// #include "Die.h"
// #include "Dice.h"

using namespace std;

//Die.h
class Die{
private: 
    int value;

public:
    Die();
    void roll();
    int get_value() const;
    void get_image();
    void set_value(int);
};

//Dice.h
class Dice{
private: 
    vector<Die> dice;

public:
    Dice();
    void add_die(Die die);
    void roll_all();
    vector<Die> get_dice() const;
    int get_total();
};

//Die.cpp
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

//Dice.cpp
Dice::Dice(){}

void Dice::add_die(Die die){
    dice.push_back(die);
}

void Dice::roll_all() {
    for(Die& die : dice){
        die.roll();
    }
}

vector<Die> Dice::get_dice() const{
    return dice;
}

int Dice::get_total(){
    int total = 0;
    for(Die& die : dice){
        total += die.get_value();
    }
    return total;
}

int main(){
    cout << "THe Dice Roller Program\n";

    for(int i = 1; i <= 6; i++){
        Die die;
        die.set_value(i);
        die.get_image();
    }

    //get number of dice from user
    int count;
    cout << "\nEnter the number of dice to roll: ";
    cin >> count;

    //create Dice object and add Die objects to it
    Dice dice;
    for(int i = 0; i < count; ++i){
        Die die;
        dice.add_die(die);
    }

    char choice = 'y';
    while(choice == 'y'){
        //roll the dice
        dice.roll_all();
        cout << "Your Roll: " << endl;
        for(Die die: dice.get_dice()){
            die.get_image();
        }
        cout << endl;
        cout << "Your Total: " << dice.get_total() << endl;

        cout << "Roll agian? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";
}