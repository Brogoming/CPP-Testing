#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;

void get_monthly_weight(double* weights, string* months, int numMonths){
    if(weights == nullptr || months == nullptr) return;
    for(int i = 0; i < numMonths; ++i){
        cout << months[i] << ": ";
        cin >> weights[i];
    }
    cout << endl;
}

double get_total(double* weights, int numMonths){
    double total = 0;
    if(weights){
        for(int i = 0; i < numMonths; ++i){
            total += weights[i];
        }
    }
    return total;
}

int main()
{
	const int numMonths = 12;
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    double weights[numMonths] = {0.0};

	cout << "Welcome to the Weight Tracker program!\n\n"
		 << "Please enter your weight at the beginning of each month:\n";

    get_monthly_weight(weights, months, numMonths);
    double total = get_total(weights, numMonths);
    auto min = min_element(weights, weights + numMonths);
    auto max = max_element(weights, weights + numMonths);

    cout << "Maximum Weight: " << *max << endl;
    cout << "Minimum Weight: " << *min << endl;
    cout << "Average Weight: " << total/numMonths << endl << endl;

}
