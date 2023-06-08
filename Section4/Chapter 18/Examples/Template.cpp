#include <iostream>
#include <string>

using namespace std;

template<typename T>
// template<class T> also works

void display(T value){
    cout << value << endl;
}

int main(){

    display(5);
    display('D');
    display(234.433);
    display("Hello");
    display<int>('D'); //to get the specific value, returns 68

    return 0;
}