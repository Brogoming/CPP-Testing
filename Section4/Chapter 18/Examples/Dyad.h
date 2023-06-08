#ifndef MURACH_DYAD_H
#define MURACH_DYAD_H

template<typename T1, typename T2>
class Dyad {
    private:
        T1 one;
        T2 two;
    public:
        Dyad(T1 val1, T2 val2){
            one = val1;
            two = val2;
        }
        T1 get_first(){return one;}
        T2 get_second(){return two;}
};

#endif