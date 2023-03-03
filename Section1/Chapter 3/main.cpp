#include <iostream>

using namespace std;

int main() {
	int saga;
	cout << "Favorite Star Wars Saga:\n" << "Prequel(1)\n" << "Original(2)\n" << "Sequel(3)\n" << ": ";

	cin >> saga;
	switch (saga) {
		case 1:
			cout << "The Phantom Menace (1999)\n";
			cout << "Attack of the Clones (2002)\n";
			cout << "Revenge of the Sith (2005)\n";
			break;
		case 2:
			cout << "A New Hope (1977)\n";
			cout << "The Empire Strikes Back (1980)\n";
			cout << "Return of the Jedi (1983)\n";
			break;
		case 3:
			cout << "The Force Awakens (2015)\n";
			cout << "The Last Jedi (2017)\n";
			cout << "The Rise of Skywalker (2019)\n";
			break;
		default:
			// I know this wouldn't make sense in terms of how to use switch and if but I didn't want to make this into an overly complicated program
			if (saga == 0) { 
				cout << "How dare you not like Star Wars.\n";
			}
			else {
				cout << "I wish there were more too\n";
			}
			break;
	}
}