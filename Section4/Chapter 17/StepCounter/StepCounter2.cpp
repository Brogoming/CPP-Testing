#include <iostream>
#include <vector>

using namespace std;

void get_weekly_steps(int* steps, char* days, int numDays);
double get_total(int* steps, int numDays);

class Counter {
    private:
        vector<int> steps;
    public: 
        vector<char> days = {'M', 'T', 'W', 'T', 'F', 'S', 'S'};
        Counter& get_weekly_steps();
        double get_total();
};

int main(){
    cout << "Welcome to the Weekly Step Counter program!\n\n"
         << "Please enter your steps for the week:\n";
    Counter steps;
    double total = steps.get_weekly_steps().get_total(); //chaining
    double avg = total/steps.days.size();

    cout << "Total steps for the week: " << total << '\n'
         << "Average daily steps: " << avg << "\n\n";
    
    return 0;
}

Counter& Counter::get_weekly_steps(){
    int dailySteps;
    for(char day: this->days){
        cout << day << ": ";
        cin >> dailySteps;
        this->steps.push_back(dailySteps);
    }
    cout << endl;
    return *this;
}

double Counter::get_total(){
    double total = 0;
    for(int s: this->steps){
        total += s;
    }
    return total;
}