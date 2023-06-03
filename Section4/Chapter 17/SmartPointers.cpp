#include <memory>
#include <iostream>

using namespace std;

unique_ptr<int[]> create_array(unsigned int size){
    auto arr = make_unique<int[]>(size);
    return arr;
}

int main(){
    unique_ptr<int> ptr(new int);
    *ptr = 4;
    *ptr *= *ptr;
    cout << *ptr << endl;

    unique_ptr<int[]> arr1(new int[10]);
    for(int i = 0; i < 10; ++i){
        arr1[i] = i;
    }
    for(int i = 0; i < 10; ++i){
        cout << arr1[i] << ' ';
    }
    cout << endl;

    unsigned int size =0;
    cout << "Please enter the size of the array: ";
    cin >> size;

    auto arr = create_array(size);
    for(int i = 0; i < size; ++i){
        cout << arr[i] << ' ';
    }
    return 0;
}