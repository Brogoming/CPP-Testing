#ifndef MURACH_TEMP_H
#define MURACH_TEMP_H

class Temp{
    private:
        int celsius;
        int fahrenheit;

    public:
        Temp();
        double get_celsius();
        double get_fahrenheit();
        void set_celsius(double c);
        void set_fahrenheit(double f);

};

#endif //MURACH_TEMP_H