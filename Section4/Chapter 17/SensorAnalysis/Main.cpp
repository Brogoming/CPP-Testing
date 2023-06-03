#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include "HeapArray.cpp"

using namespace std;

void load_sensor_data(HeapArray& data);

int main(){
    cout << "Sensor Analysis Program\n\n";

    int numDays = 0;
    cout << "Enter the number of day to analyze: ";
    cin >> numDays;
    cout << endl;

    const int secondsPerDay = 86400;
    int totalSeconds = numDays * secondsPerDay;

    HeapArray data(totalSeconds);
    load_sensor_data(data);

    double total = accumulate(data.begin(), data.end(), 0);
    auto min = min_element(data.begin(), data.end());
    auto max = max_element(data.begin(), data.end());

    cout << "Number of sensor readings over " << numDays << " days: " << data.size() << endl;
    cout << "Average reading: " << (total / data.size()) << endl;
    cout << "Lowest days: " << *min << endl;
    cout << "Highest days: " << *max << endl;

    return 0;
}

void load_sensor_data(HeapArray& data){
    srand(time(nullptr));
    int adjust = rand() % 70 + 10; //10 - 70

    int num = 0;
    for(int i = 0; i < data.size(); ++i){
        num = rand() % 100 + 1;
        data[i] = (num < adjust) ? num + adjust : num;
    }
}