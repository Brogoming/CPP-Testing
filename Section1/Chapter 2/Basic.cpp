#include <iostream>

using namespace std;

int main(){
    cout << "Welcome to the Calorie Calculator\n\n";

    //get number of servings from user
    double servings;
    cout << "Enter servings per food item: ";
    cin >> servings;

    //get number of calories from user
    double calories;
    cout << "Enter calories per serving: ";
    cin >> calories;

    //calculate total calories
    double totalCalories = servings * calories;

    //display total calories
    cout << "Total Calories: " << totalCalories << endl << endl;

    return 0; 
}