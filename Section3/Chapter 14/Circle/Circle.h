#ifndef MURACH_CIRCLE_H
#define MURACH_CIRCLE_H

class Circle{
    private:
        double radius;
        const double pi = 3.14159;

    public:
        Circle(double r);
        double get_radius();
        void set_radius(double r);
        double get_circ();
        double get_diameter();
        double get_area();
};

#endif //MURACH_CIRCLE_H