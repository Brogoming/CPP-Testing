#include <iostream>
#include <string>
#include "HeapArray.h"

using namespace std;

template<typename T>
void display(HeapArray<T>&);

int main(){
    HeapArray<int> nums(11);
    for(int i = 0; i < nums.size(); ++i){
        nums[i] = (i + 1) * 10;
    }
    display(nums);

    HeapArray<string> words(3);
    words[0] = "hello";
    words[1] = "good";
    words[2] = "buddy";
    display(words);
}

template<typename T>
void display(HeapArray<T>& arr){
    for(T elem : arr){
        cout << elem << ' ';
    }
    cout << endl;
}