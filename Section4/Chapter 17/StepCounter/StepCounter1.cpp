#include <iostream>

using namespace std;

void get_weekly_steps(int* steps, char* days, int numDays);
double get_total(int* steps, int numDays);

int main(){
    const int numDays = 7;
    char days[] = "MTWTFSS"; //built in array for days
    int steps[numDays] = {0}; //built in array for steps

    cout << "Welcome to the Weekly Step Counter program!\n\n"
         << "Please enter your steps for the week:\n";

    get_weekly_steps(steps, days, numDays);
    double total = get_total(steps, numDays);
    double avg = total/numDays;

    cout << "Total steps for the week: " << total << '\n'
         << "Average daily steps: " << avg << "\n\n";
    
    return 0;
}

void get_weekly_steps(int* steps, char* days, int numDays){
    if(steps == nullptr || days == nullptr) return;
    for(int i = 0; i < numDays; ++i){
        cout << days[i] << ": ";
        cin >> steps[i];
    }
    cout << endl;
}

double get_total(int* steps, int numDays){
    double total = 0;
    if(steps){ //same as steps != nullptr
        for(int i = 0; i < numDays; ++i){
            total += steps[i];
        }
    }
    return total;
}