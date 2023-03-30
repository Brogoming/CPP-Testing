#include "Die.h"

Dice::Dice(){}

void Dice::add_die(Die die){
    dice.push_back(die);
}

int Dice::roll_all() const{
    for(Die& die : dice){
        die.roll();
    }
}

std::vector<Die> Dice::get_dice() const{
    return dice;
}