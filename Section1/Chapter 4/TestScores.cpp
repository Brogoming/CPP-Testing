#include <iostream>

using namespace std;

int main(){
    cout << "Enter test scores from 0 to 100.\n"
         << "To end the program, enter -1.\n\n";

    //define variables
    int score = 0;
    int count = 0;
    double total = 0.0;
    while(score != -1){
        cout << "Enter score: ";
        cin >> score;

        if(score > 100){
            cout << "Score must be from 0 to 100. Try again.\n";
        } else if(score > -1){
            ++count;
            total+=score;
        } else if (score < -1){
            cout << "Score must be from 0 to 100. Try again.\n";
        }
    }

    //calcuate average score
    double avgScore = 0.0;
    if(count > 0){
        avgScore = total / count;
    }

    //display the score count, total, and average
    cout << endl
         << "Score count:   " << count << endl
         << "Score total:   " << total << endl
         << "Average score: " << avgScore << endl;
}