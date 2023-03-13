#include <iostream>
#include <cmath>

using namespace std;

double calculate_total(int scores[], int scoreCount);

int main(){
    const int capacity = 50;
    int scores[capacity] {0}; //set each element of the array to zero

    cout << "The Test Scores Program\n\n";

    cout << "Enter test scores (" << capacity << " max).\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n\n";

    //initialize variables
    int scoreCount = 0, score = 0;

    //prevent out of bounds access by making sure score count is less than array capacity
    while(score != -1 && scoreCount < capacity){
        cout << "Enter Score: ";
        cin >> score;

        if(cin.fail()){
            cin.clear(); //clear bad input flag
            cin.ignore(1000, '\n'); //discard input up to end of line
            cout << "Invalid number. Try again.\n";
        } else if(score > 100){
            cout << "score must be between 0 and 100. Try again.\n";
        } else if(score < -1){
            cout << "Score can't be a negative number. Try again.\n";
        } else if(score > -1){
            scores[scoreCount] = score; //store score in array
            ++scoreCount;
        }
    }
    cout << endl;

    if(scoreCount == 0){
        cout << "No scores entered.\n\n";
    } else {
        //calculate total average scores
        double total = calculate_total(scores, scoreCount);
        double average = total / scoreCount;
        average = round(average*10)/10;

        //display the score count, score total, and average score
        cout << "Score count:     " << scoreCount << endl
             << "Score total:     " << total << endl
             << "Average score:   " << average << endl << endl;
    }

    return 0;
}

double calculate_total(int scores[], int scoreCount){
    double total = 0.0;
    for(int i = 0; i < scoreCount; ++i){
        total += scores[i];
    }
    return total;
}