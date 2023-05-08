#include <iostream>
#include <map>
#include <string>

using namespace std;

char get_choice() {
	char choice;
	cout << "Continue (y/n)?: ";
	cin >> choice;
	cout << endl;
	return choice;
}

void display_codes(const map<string, string>& countries) {
	cout << "Country codes: ";
	// display codes
    for(pair<string, string> p : countries){
        cout << p.first << " ";
    }

	cout << endl << endl;
}

void display_country(const map<string, string>& countries) {
	string code;
	cout << "Enter a country code: ";
	cin >> code;
	string upper_code = "";
	for (char c : code) {
		upper_code += toupper(c);
	}

	// get iterator for map element with code
    string country;
    auto iter = countries.find(upper_code);
    if(iter == countries.end()){
        cout << "Country code not found.\n\n";
    } else {
        country = countries.at(upper_code);
        cout << "You selected " << country << "!\n\n";
    }
}

int main()
{
	map<string, string> countries{ {"CA", "Canada"}, {"US", "United States"}, {"MX", "Mexico"} };

	cout << "The Country Codes Program\n\n";

	// display the country codes
    display_codes(countries);

	// while the user indicates they want to continue, display a country
    char again = 'y';
    while(again == 'y'){
        display_country(countries);
        cout << "Continue? (y/n): ";
        cin >> again;
    }
    cout << "Bye!\n\n";
}

