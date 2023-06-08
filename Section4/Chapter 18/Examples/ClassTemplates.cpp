#include <iostream>
#include <string>
#include "Dyad.h"

using namespace std;

int main(){

    //if there is only one template in the class you can only use the same data type for both variables
    // Dyad<string> name("Bjarne", "Stroustrup");
    // cout << name.get_first() << ' ' << name.get_second() << endl;
    // Dyad<int> xy(10, 20);
    // cout << xy.get_first() << ' ' << xy.get_second() << endl;

    //if you have multiple data types in the class you can pass two different variables in 
    Dyad<string, double> object("Hammer", 15.99);
    cout << object.get_first() << ' ' << object.get_second() << endl;

    return 0;
}