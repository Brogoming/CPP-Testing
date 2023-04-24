#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Guest Book\n\n";

    string firstName;
    cout << "First name:\t";
    cin >> firstName;
    cin.ignore(100, '\n'); //discard left over chars and newline

    char middleInitial;
    cout << "Middle initial:\t";
    middleInitial = cin.get(); //get first char only
    cin.ignore(100, '\n');

    string lastName;
    cout << "Last name:\t";
    getline(cin, lastName);

    string city;
    cout << "City:\t\t";
    getline(cin, city);

    string country;
    cout << "Country:\t";
    getline(cin, country);

    cout << "\nEntry\n"
         << firstName + " " + middleInitial + " " + lastName + '\n'
         << city + ", " + country + "\n\n";

}