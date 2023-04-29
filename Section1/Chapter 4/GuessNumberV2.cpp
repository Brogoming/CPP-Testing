#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int upperLimit = 10;
    cout << "Guess the number!\n";
    cout << "I'm thinking of a number between 1 to " << upperLimit << "\n\n";

    //get a random number between 1 and upper limit
    srand(time(nullptr));
    int number = rand() % upperLimit;
    ++number;

    int count = 1;
    int guess;
    cout << "Your guess: ";
    cin >> guess;
    while(guess != number){
        if(guess < 1 || guess > upperLimit){
            cout << "Invalid guess. Try again.\n";
        } else {
            if(guess < number) {
                cout << "Too low.\n";
            } else if(guess > number){
                cout << "Too high.\n";
            }
            ++count;
        }
        cout << "Your guess: ";
        cin >> guess;
    }
    cout << "You guessed it in " << count << " tries.\n\n";
    cout << "Bye!\n\n";
}