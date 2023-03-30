#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

int main(){
    cout << "THe Dice Roller Program\n\n";

    //get number of dice from user
    int count;
    cout << "Enter the number of dice to roll: ";
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
        cout << "Your Roll: ";
        for(Die die: dice.get_dice()){
            cout << die.get_value() << " ";
        }
        cout << endl;

        cout << "Roll agian? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";
}