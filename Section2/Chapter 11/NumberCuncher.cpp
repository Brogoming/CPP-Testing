#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void display_int(int num){
  cout << num << ' ';
}

int main() {
  cout << "The Number Cruncher Program\n\n";

  //create an empty vector with space for 11 elements
  vector<int> numbers;
  numbers.reserve(11);

  //fill the vector with random numbers
  srand(time(nullptr));
  for (int i = 0; i< numbers.capacity(); ++i){
    int number = rand() % 30;
    numbers.push_back(number);
  }

  //displays all of the unordered numbers
  cout << numbers.size() << " Random Numbers: ";
  for_each(numbers.begin(), numbers.end(), display_int);
  cout << endl;

  //displays all of the sorted numbers
  sort(numbers.begin(), numbers.end());
  cout << numbers.size() << " Sorted Numbers: ";
  for_each(numbers.begin(), numbers.end(), display_int);
  cout << endl;

  //sums up the total of the numbers
  int sum = accumulate(numbers.begin(), numbers.end(), 0);
  cout << "Sum = " << sum << ' ';

  //average of the numbers
  double avg = sum / numbers.size();
  cout << "Average: = " << avg << ' ';

  //the highest number
  auto maxIter = max_element(numbers.begin(), numbers.end());
  cout << "Max: = " << *maxIter << ' ';

  //the lowest number
  auto minIter = min_element(numbers.begin(), numbers.end());
  cout << "Min: = " << *minIter << ' ';
  cout << endl;

  //does a binary search to see if the number is within the numbers vector
  int num = 10;
  bool numExists = binary_search(numbers.begin(), numbers.end(), num);
  if(numExists){
    //counts the amount of times the number shows up
    int c = count(numbers.begin(), numbers.end(), num);
    cout << "The number " << num << " occurs " << c << " time(s).\n";
  } else {
    cout << "These numbers do Not include " << num << ".\n";
  }
}