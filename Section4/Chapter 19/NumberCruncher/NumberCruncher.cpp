#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include "find_midpoint.h"
#include "MyVector.cpp"

using namespace std;

void display_int(int num){
  cout << num << ' ';
}

int main() {
  cout << "The Number Cruncher Program\n\n";

  //create an empty vector with space for 11 elements
  MyVector<int> numbers;
  numbers.reserve(10);

  //fill the vector with random numbers
  srand(time(nullptr));
  for (int i = 0; i< numbers.capacity(); ++i){
    int number = rand() % 30; //0 - 29
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

  //use custom algorithm
  auto midIter = find_midpoint(numbers.begin(), numbers.end());
  cout << "Midpoint: " << *midIter << ' ';

  //calcuate median
  double median;
  if(numbers.size() % 2 != 0){
    median = *midIter;
  } else {
    double midVal = *midIter;
    double prevVal = *(--midIter);
    median = (midVal + prevVal) / 2;
  }
  cout << "Median = " << median << "\n\n";
  return 0;
}