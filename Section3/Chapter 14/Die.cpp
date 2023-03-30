#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die(){
    srand(time(nullptr));
    value = 1;
}

void Die::roll(){
    value = rand() % 6; //0 <= value <= 5
    ++value; //1 <= value <= 6
}

int Die::get_value() const{
    return value;
}