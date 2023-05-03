#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std; 

int main() {
	char choice = 'y';
    vector<double> investments;
    vector<double> rates;
    vector<int> allYears;
    vector<double> futureValues;
	cout << "The Future Value Calculator\n\n";

	while (choice == 'y' || choice == 'Y') {
		double monthlyInvest;
		cout << "Enter monthly investment:\t";
		cin >> monthlyInvest;
        investments.push_back(monthlyInvest);

		double yearlyRate;
		cout << "Enter yearly interest rate:\t";
		cin >> yearlyRate;
        rates.push_back(yearlyRate);

		double years;
		cout << "Enter number of years:\t\t";
		cin >> years;
        allYears.push_back(years);

		double monthlyRate = yearlyRate / 12 / 100;
		int months = years * 12;
		double futureValue = 0;
		for (int i = 1; i <= months; ++i) {
			futureValue = (futureValue + monthlyInvest) * (1 + monthlyRate);
		}

		futureValue = round(futureValue * 100) / 100;
        futureValues.push_back(futureValue);
		cout << "Future value: \t\t\t" << futureValue << "\n\n";

		cout << "Conmtinue? (y/n):\t\t";
		cin >> choice;
		cout << endl;
	}
    cout << setw(16) << right << "Monthly Investments" 
         << setw(16) << right << "Yearly Rate" 
         << setw(16) << right << "Years" 
         << setw(16) << right << "Future Value" << endl;
    for(int i = 0; i < investments.size(); ++i){
        cout << fixed << setprecision(2)
             << right << setw(16) << investments[i]
             << right << setw(16) << rates[i]
             << right << setw(16) << allYears[i]
             << right << setw(16) << futureValues[i] << endl;
    }

	cout << "Bye!\n\n";
}