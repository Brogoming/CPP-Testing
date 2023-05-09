#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// struct MinScore{
//   int minimum;  

//   MinScore(int num){ //constructor
//     minimum = num;
//   }

//   bool operator()(int value) const { //operator
//     return value >= minimum;
//   }
// };

void display(int num);
int sort_descending(int a, int b);

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
        int total = accumulate(scores.begin(), scores.end(), 0);

        cout << endl;
        sort(scores.begin(), scores.end(), sort_descending);
        for_each(scores.begin(), scores.end(), display);
        auto highScore = max_element(scores.begin(), scores.end());
        auto lowScore = min_element(scores.begin(), scores.end());
        cout << "\nHighest Score: " << *highScore << endl;
        cout << "Lowest Score: " << *lowScore << endl;
        int minimum = 90;
        auto minScore = [&] (int value) -> bool {
            return value >= minimum;
        };
        auto above90 = count_if(scores.begin(), scores.end(), minScore);
        minimum = 80;
        auto above80 = count_if(scores.begin(), scores.end(), minScore);
        cout << "Scores 90 or above: " << above90 << endl;
        cout << "Scores 80 or above: " << above80 << endl;

        // cout << "This student has " << count(scores.begin(), scores.end(), 100) << " perfect score(s)." << endl;

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

void display(int num){
    cout << num << ' ';
}

int sort_descending(int a, int b){
    return a > b;
}