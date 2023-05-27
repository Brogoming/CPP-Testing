#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Die.cpp"
#include "Dice.cpp"

using namespace std;

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