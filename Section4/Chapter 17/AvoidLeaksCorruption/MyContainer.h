#ifndef MURACH_MYCONTAINER_H
#define MURACH_MYCONTAINER_H

#include <iostream>

class MyContainer{
    private:
        int* elements = nullptr;
        int size = 10;
    public:
        //constructor
        MyContainer(){
            elements = new int[size]; //allocating free space
            // std::cout << "Memory allocated for MyContainer object\n";
        }

        //deconstructor
        ~MyContainer(){
            delete[] elements;
            // std::cout << "Memory deallocated for MyContainer object\n";
        }

        //copy constructor
        MyContainer(const MyContainer& tocopy){
            elements = new int[size];
            for(int i = 0; i < size; ++i){ //deep copy
                elements[i] = tocopy.elements[i];
            }
        }

        //copy assignment operator
        MyContainer& operator= (const MyContainer& tocopy){
            auto temp = new int[size]; //allocate new array
            for(int i = 0; i < size; ++i){ //deep copy
                temp[i] = tocopy.elements[i];
            }
            delete[] elements; //delete old
            elements = temp; //assign new
            return *this; //return self-reference
        }

        //move constructor
        MyContainer(MyContainer&& tomove){
            elements = tomove.elements; //assign pointer to data
            tomove.elements = nullptr; //remove pointer to data
        }

        //move assignment operator
        MyContainer& operator= (MyContainer&& tomove){
            delete[] elements; //deallocate existing memory
            elements = tomove.elements; //assign pointer to data
            tomove.elements = nullptr; //remove pointer to data
            return *this; //return self-reference
        }
};

#endif