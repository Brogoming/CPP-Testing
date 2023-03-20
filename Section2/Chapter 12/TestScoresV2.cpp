#include <iostream>
#include <cmath>

using namespace std;

double calculate_total(int scores[], int scoreCount);

int main(){
    int c = 0;
    const int capacity = 3;
    const int maxStudents = 10;
    int scores[maxStudents][capacity]; //set each element of the array to zero

    cout << "The Test Scores Program\n\n";

    cout << "Enter test scores (" << capacity << " per student, " << maxStudents << " max students.)\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n\n";

    //initialize variables
    int scoreCount = 0, score = 0, studentCount = 0;

    //prevent out of bounds access by making sure score count is less than array capacity
    while(score != -1 && studentCount < maxStudents){
        cout << "Student " << studentCount + 1 << '\n';
        scoreCount = 0; //reset scoreCount
        score = 0; //reset score
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
                scores[studentCount][scoreCount] = score; //store score in array
                ++scoreCount;
            }
        }
        ++studentCount;
        cout << endl;
    }
    cout << endl;

    if(studentCount == 0){
        cout << "No scores entered.\n\n";
    } else {
        for(int i = 0; i < studentCount - 1; i++){
            c = 0;
            cout << "Student " << i + 1 << ": ";
            for(int score : scores[i]){
                c++;
            }
            for(int j = 0; j < c; j++){
                cout << scores[i][j] << " ";
            }
            double total = calculate_total(scores[i], c);
            double average = total / c;
            average = round(average*10)/10;

            cout << "\tAvg score: " << average << endl;
        }
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