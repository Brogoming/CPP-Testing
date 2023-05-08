#include <iostream>
#include <array>

using namespace std;

//define const of array length
const int len = 10;

//define function that accepts the array
int calculate_total(const array<int, len>& scores){
    int total = 0;
    for(int score : scores){
        total += score;
    }
    return total;
}

int main(){
    array<int, len> scores{0}; //creates the array and has each element = 0

    cout << "The Test Scores Program\n\n" << "Enter " << len << " scores or -1 to exit.\n\n";

    //get scores from user
    int scoreCount = 0;
    while(scoreCount < scores.size()){
        int score;
        cout << "Enter score: ";
        cin >> score;
        if(score == -1){
            break;
        }
        scores[scoreCount] = score;
        ++scoreCount;
    }
    cout << endl;

    int total = calculate_total(scores);
    cout << "Score count: " << scoreCount << endl;
    cout << "Score total: " << total << endl;
}