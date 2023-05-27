#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Die.cpp"
#include "Dice.cpp"

using namespace std;

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