#ifndef MURACH_DIE_H
#define MURACH_DIE_H

class Die{
private: 
    int value;

public:
    Die();
    void roll();
    int get_value() const;
    void get_image();
    void set_value(int);
};

#endif //MURACH_DIE_H