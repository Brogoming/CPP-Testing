#include <iostream>
#include <string>
#include "MyList.h"

using namespace std;

template<typename T>
void display(MyList<T>& elements) {   // don't test copy constructor
    for (T elem : elements) {
        cout << elem << '|';
    }
    cout << endl;
}

int main() {
    // test push_back() function
    cout << "TESTING\n";
    MyList<string> tasks;
    tasks.push_back("Go to store");
    tasks.push_back("Feed cats");
    tasks.push_back("Check email");
    tasks.push_back("Feed cats");
    tasks.push_back("Brush teeth");
    display(tasks);

    // test size() function
    cout << "size():     " << tasks.size() << endl;

    // test pop_back() function
    cout << "pop_back(): ";
    tasks.pop_back();
    display(tasks);

    // test at() function
    cout << "at(0):      " << tasks.at(0) << endl;
    cout << "at(size-1): " << tasks.at(tasks.size() - 1) << endl;

    // test remove() function
    cout << "remove():   ";
    tasks.remove("Feed cats");
    display(tasks);

    //push_back
    cout << "push_back():";
    tasks.push_back("Go on a walk");
    display(tasks); 

    // test size() function
    cout << "size():     " << tasks.size() << endl;
}