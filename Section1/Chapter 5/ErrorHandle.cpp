#include <iostream>
#include <limits>

using namespace std;

int main(){
    double num;
    while(true){
        cout << "Enter a number between (1-100): ";
        cin >> num;

        //if the extraction operation fails, try again
        if(cin.fail()){
            cout << "That's not a valid number. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        //check the range of the number
        if(num < 1){
            cout << "Number must be greater than 0. Try again.\n";
        } else if(num > 100){
            cout << "Number must be 100 or less. Try again.\n";
        } else { //number is in range
            break;
        }
    }
    cout << "Your number is " << num << endl;
}