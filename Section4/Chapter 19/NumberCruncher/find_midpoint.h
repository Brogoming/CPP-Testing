#ifndef MURACH_MIDPOINT_H
#define MURACH_MIDPOINT_H

template<typename BiDirIter>
BiDirIter find_midpoint(BiDirIter begin, BiDirIter end){
    //if range is empty, return the off-the-end iterator
    if(begin == end){
        return end;
    }

    //alternate decrementing end iterator and incremanting begin iterator untill bioth point to the same element
    int counter = 0;
    while(begin != end){
        if(counter % 2 == 0){ //counter is even
            --end;
        } else { //counter is odd
            ++begin;
        }
        ++counter;
    }
    return begin;
}

#endif