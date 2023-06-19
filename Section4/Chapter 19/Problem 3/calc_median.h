#ifndef MURACH_CALCMEDIAN_H
#define MURACH_CALCMEDIAN_H

template<typename BidirIter>
double calc_median(BidirIter begin, BidirIter end) {
    // if range is empty, return the off-the-end iterator 
    if (begin == end) {
        return *end;
    }

    // alternate decrementing end iterator
    // and incrementing begin iterator
    // until both point to the same element
    int counter = 0;
    while (begin != end) {
        if (counter % 2 == 0) {  // counter is even
            --end;
        }
        else {                   // counter is odd
            ++begin;
        }
        ++counter;
    }

    // calculate median
    double median;
    if (counter % 2 == 0) {  // odd - median is same as midpoint
        double mid_val = *begin;
        double prev_val = *(--begin);
        median = (mid_val + prev_val) / 2;
    }
    else {    // even - median is sum of midpoint and prev divided by 2
        median = *begin;
    }
    return median;
}

#endif