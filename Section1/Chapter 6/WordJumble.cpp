#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "Let's Play Word Jumble!\n\n"
         << "Enter 'hint' for hint.\n"
         << "Enter 'exit' for exit.\n\n";

    //vector of possible words
    vector<string> words {"guitar", "violin", "tapestry"};

    //get random word
    srand(time(nullptr));
    int index = rand() % words.size();
    string word = words[index];

    //jumble the word
    string jumbleWord = word;
    auto length = word.size();
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
    string guess = "";
    while(true){
        cout << "Guess: ";
        cin >> guess;
        cin.ignore(1000, '\n');

        if(guess == word){
            cout << "Congrats you guessed it!\n\n";
            break;
        } else if(guess == "hint"){
            cout << "Hint: ";
            for(int i = 0; i < word.length(); ++ i){
                if(i < hintCount){
                    cout << static_cast<char>(toupper(word[i])) << ' ';
                } else {
                    cout << '_' << ' ';
                }
            }
            cout << "\n\n";
            ++hintCount;
        } else if(guess == "exit"){
            cout << "Bye!\n\n";
            break;
        } else {
            cout << "Nope. Try again!\n\n";
        }
    }
}