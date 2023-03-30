void Dice::add_die(Die die){
    dice.push_back(die);
}

int Dice::roll_all() const{
    for(Die& die : dice){
        die.roll();
    }
}