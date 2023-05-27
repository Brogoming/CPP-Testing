#include "Dice.h"

using namespace std;

Dice::Dice(){}

void Dice::add_die(Die die){
    dice.push_back(die);
}

void Dice::roll_all(){
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