#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Die.cpp"

using namespace std;

//structure of game variables
struct GameState{
    int turn = 1;
    int score = 0;
    int scoreThisTurn = 0;
    bool turnOver = false;
    bool gameOver = false;
    Die die;
};

//declare functions
void display_rules();
void play_game(GameState&);
void take_turn(GameState&);
void roll_die(GameState&);
void hold_turn(GameState&);

int main(){
    display_rules();
    GameState game;
    play_game(game);
}

//define functions
void display_rules(){
    cout << "Let's Play PIG!\n\n"
        << "* See how many turns it takes you to get to 20.\n"
        << "* Turn ends when you hold or roll a 1.\n"
        << "* If you roll a 1, you lose all points for the turn.\n"
        << "* If you hold, you save all points for the turn.\n\n";
}

void play_game(GameState& game){
    while(!game.gameOver){
        take_turn(game);
    }
    cout << "Game over!\n";
}

void take_turn(GameState& game){
    cout << "TURN " << game.turn << endl;
    game.turnOver = false;
    while(!game.turnOver){
        char choice;
        cout << "Roll or hold? (r/h): ";
        cin >> choice;

        if(choice == 'r'){
            roll_die(game);
        } else if(choice == 'h'){
            hold_turn(game);
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void roll_die(GameState& game){
    game.die.roll();

    cout << "Die: " << game.die.get_value() << endl;
    if(game.die.get_value() == 1){
        game.scoreThisTurn = 0;
        game.turn += 1;
        game.turnOver = true;
        cout << "Turn over. No Score.\n\n";
    } else {
        game.scoreThisTurn += game.die.get_value();
    }
}

void hold_turn(GameState& game){
    game.score += game.scoreThisTurn;
    game.turnOver = true;
    cout << "Score for turn: " << game.scoreThisTurn << endl;
    cout << "Total score: " << game.score << "\n\n";
    game.scoreThisTurn = 0;

    if(game.score >=20){
        game.gameOver = true;
        cout << "You finished in " << game.turn << " turns!\n\n";
    } else {
        game.turn += 1;
    }
}