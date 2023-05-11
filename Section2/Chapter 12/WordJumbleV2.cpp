#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    const int numWords = 3;
    const int numLetters = 15;
    cout << "Let's Play Word Jumble!\n\n"
         << "Enter 'hint' for hint.\n"
         << "Enter 'exit' for exit.\n\n";

    //2D array of possible words
    char words[numWords][numLetters] = {{"guitar"}, {"violin"}, {"tapestry"}};

    //get random word
    srand(time(nullptr));
    int index = rand() % numWords;
    char word[15] = "";
    for(int i = 0; i < strlen(words[index]); i++){
        word[i] = words[index][i];
    }

    // //jumble the word
    char jumbleWord[15] = "";
    strncpy(jumbleWord, word, 15);
    auto length = strlen(jumbleWord);
    for (int i = 0; i < length; ++i){
        int j = rand() % length;
        char temp = jumbleWord[i];
        jumbleWord[i] = jumbleWord[j];
        jumbleWord[j] = temp;
    }

    //display jumbled word
    cout << "The jumble is ... ";
    for(char c : jumbleWord){
        cout << static_cast<char>(toupper(c));
    }
    cout << "\n\n";

    //loop until user gets it or says exit
    int hintCount = 1;
    char guess[15] = "";
    while(true){
        cout << "Guess: ";
        cin.getline(guess, 15);
        // cin >> guess;
        // cin.ignore(1000, '\n');

        if(strcmp(guess, word) == 0){
            cout << "Congrats you guessed it!\n\n";
            break;
        } else if(strcmp(guess, "hint") == 0){
            cout << "Hint: ";
            for(int i = 0; i < length; ++ i){
                if(i < hintCount){
                    cout << static_cast<char>(toupper(word[i])) << ' ';
                } else {
                    cout << '_' << ' ';
                }
            }
            cout << "\n\n";
            ++hintCount;
        } else if(strcmp(guess, "exit") == 0){
            cout << "Bye!\n\n";
            break;
        } else {
            cout << "Nope. Try again!\n\n";
        }
    }
}