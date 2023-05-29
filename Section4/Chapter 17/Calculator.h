#ifndef MURACH_CALCULATOR_H
#define MURACH_CALCULATOR_H

class Calculator{
    private:
        int result;
    public:
        //this-> is optional 
        Calculator& multiply(int a, int b){
            this->result = a * b;
            return *this;
        }

        Calculator& square_result(){
            this->result *= this->result;
            return *this;
        }

        int get_result(){
            return this->result;
        }
};

#endif