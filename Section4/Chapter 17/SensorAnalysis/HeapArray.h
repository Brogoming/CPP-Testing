#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

class HeapArray{
    private:
        int arraySize;
        int* arr = nullptr;
    public:
        //constructors
        HeapArray(const int);
        HeapArray(const HeapArray& tocopy); //copy constructor
        HeapArray(HeapArray&& tomove); //move constructor

        //deconstructor
        ~HeapArray();

        //assignment operators
        HeapArray& operator= (const HeapArray& tocopy); //copy assignment
        HeapArray& operator= (HeapArray&& tomove); //move assignment

        //subscripts operator
        int& operator[] (int i);

        //member functions
        int size() const;
        int* begin();
        int* end();
};

#endif