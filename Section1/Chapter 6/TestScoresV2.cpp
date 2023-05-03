#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    cout << "Test Scores Program V2\n\n";

    cout << "Enter test scores from 0 to 100.\n"
         << "To end the program, enter -1.\n\n";

    //define variables
    int score = 0;
    vector<int> scores;
    while(score != -1){
        cout << "Enter score: ";
        cin >> score;

        if(cin.fail()){
            cin.clear(); //clear error bits
            cin.ignore(1000, '\n'); //discard the inputs up to the next line
            cout << "Invalid number. Try again.\n";
        } else if(score > 100){
            cout << "Score must be from 0 to 100. Try again.\n";
        } else if(score > -1){
            scores.push_back(score);
        } else if (score < -1){
            cout << "Score must be from 0 to 100. Try again.\n";
        }
    }

    if(scores.empty()){ //empty vector
        cout << "\nNo Scores entered.\n";
    } else {
        int total = 0;
        for(int score : scores){
            total += score;
        }

        //calcuate average score
        auto scoreCount = scores.size();
        double average = static_cast<double>(total) / scoreCount;
        average = round(average * 10) / 10;

        //display the score count, total, and average
        cout << '\n'
             << "Score count:   " << scoreCount << endl
             << "Score total:   " << total << endl
             << "Average score: " << average << endl << endl;
    }
}