#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    //use time() to get an int value
    int elapsedSeconds = time(nullptr);

    //seed the random number generator
    srand(elapsedSeconds);

    //roll the first die
    int die1 = rand()%6; //0 to 5
    die1 = die1 + 1; //1 to 6

    //roll the second die
    int die2 = rand()%6; //0 to 5
    die2 = die2 + 1; //1 to 6

    //output
    cout << "Your roll:     " << die1 << " " << die2;
}