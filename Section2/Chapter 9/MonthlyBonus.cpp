#include <iostream>

using namespace std;

enum class Department {marketing = 1, it, sales, other};

//function prototypes
void show_menu();
Department get_department();
bool check_criteria(Department);

int main(){
    cout << "The Monthly Bonus Calculator\n\n";
    show_menu();

    Department dept = get_department();
    bool bonus = check_criteria(dept);
    const double bonusAmt = 1000;
    if(bonus){
        cout << "Congrats! You earned the $" << bonusAmt << " monthly bonus.\n\n";
    } else {
        cout << "Sorry! No bonus for you this month. Keep trying!\n\n";
    }
    return 0;
}

void show_menu(){
    cout << "Departments\n"
         << static_cast<int>(Department::marketing) << " - Marketing\n"
         << static_cast<int>(Department::it) << " - IT\n"
         << static_cast<int>(Department::sales) << " - Sales\n"
         << static_cast<int>(Department::other) << " - Other\n\n";
}

Department get_department(){
    cout << "Enter department number: ";
    int choice = 0;
    cin >> choice;

    Department dept = static_cast<Department>(choice);
    if(dept < Department::marketing || dept > Department::sales){
        return Department::other;
    } else {
        return dept;
    }
}

bool check_criteria(Department dept){
    switch(dept){
        case Department::marketing:
            int viralCampaigns;
            cout << "How many of your campaigns went viral this month? ";
            cin >> viralCampaigns;
            return viralCampaigns >= 4;
        case Department::it:
            int troubleTickets;
            cout << "How many trouble tickets did you close this month? ";
            cin >> troubleTickets;
            return troubleTickets >= 10;
        case Department::sales:
            double sales;
            cout << "What were your total sales this month? ";
            cin >> sales;
            return sales >= 1000;
        case Department::other:
            char supervisorGrade;
            cout << "What was your grade from your supervisor this month? ";
            cin >> supervisorGrade;
            return tolower(supervisorGrade) == 'a';
    }
}