#include <iostream>
#include "Finance.h"

using namespace std;

double Finance::calc_future_val(double monthlyInvestment, double yearlyInterest, int years){
    //convert yearly values to monthly values
    double monthlyRate = yearlyInterest / 12 / 100;
    int months = years * 12;

    //calculate future value
    double futureVal = 0;
    for(int i = 0; i < months; ++i){
        futureVal = (futureVal + monthlyInvestment) * (1 + monthlyRate);
    }
    return futureVal;
}