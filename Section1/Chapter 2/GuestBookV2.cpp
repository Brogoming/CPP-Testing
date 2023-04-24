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

    string address;
    cout << "Address:\t";
    getline(cin, address);

    string city;
    cout << "City:\t\t";
    getline(cin, city);

    string state;
    cout << "State:\t\t";
    cin >> state;

    string postal;
    cout << "Postal Code:\t";
    cin >> postal;

    string country;
    cout << "Country:\t";
    getline(cin, country);

    cout << "\n\nENTRY\n"
         << firstName + " " + middleInitial + " " + lastName + '\n'
         << address + '\n'
         << city + ", " + state + " " + postal + "\n"
         << country << endl;

}