#include <iostream>
#include <cmath> 

using namespace std; 

int main() {
	char choice = 'y';
	cout << "The Future Value Calculator\n\n";

	while (choice == 'y' || choice == 'Y') {
		double monthlyInvest;
		cout << "Enter monthly investment:\t";
		cin >> monthlyInvest;

		double yearlyRate;
		cout << "Enter yearly interest rate:\t";
		cin >> yearlyRate;

		double years;
		cout << "Enter number of years:\t\t";
		cin >> years;

		double monthlyRate = yearlyRate / 12 / 100;
		int months = years * 12;
		double futureValue = 0;
		for (int i = 1; i <= months; ++i) {
			futureValue = (futureValue + monthlyInvest) * (1 + monthlyRate);
		}

		futureValue = round(futureValue * 100) / 100;
		cout << "Future value: \t\t\t" << futureValue << "\n\n";

		cout << "Conmtinue? (y/n):\t\t";
		cin >> choice;
		cout << endl;
	}
	cout << "Bye!";
}