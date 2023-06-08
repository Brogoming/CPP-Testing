#include <iostream>
#include <string>

using namespace std;

template<typename K, typename V>

void display(K key, V value){
    cout << key << " = " << value << endl;
}

int main(){

    display("Mary", 217);
    display(1, "Hammer");
    display("Price", 12.99);

    return 0;
}