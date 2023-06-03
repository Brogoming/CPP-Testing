#include "HeapArray.h"

//constuctors
HeapArray::HeapArray(const int size){
    arraySize = size; //set array size
    arr = new int[arraySize] {0}; //allocate memory to heap
}
HeapArray::HeapArray(const HeapArray& tocopy){
    arraySize = tocopy.arraySize; //copy size
    arr = new int[arraySize]; //allocate memory to heap

    for(int i = 0; i < arraySize; i++){ //copy array values
        arr[i] = tocopy.arr[i];
    }
}
HeapArray::HeapArray(HeapArray&& tomove){ 
    arraySize = tomove.arraySize; //copy size
    arr = tomove.arr; //reset array pointer

    tomove.arr = nullptr; //empty parameter array
    tomove.arraySize = 0; 
}

//deconstructor
HeapArray::~HeapArray(){
    delete[] arr; //deallocate memory
}

//assignment operators
HeapArray& HeapArray::operator= (const HeapArray& tocopy){ //copy
    arraySize = tocopy.arraySize; //copy size
    int* newArr = new int[arraySize]; //allocate memory to heap

    for(int i = 0; i < arraySize; ++i){ //copy array values
        newArr[i] = tocopy.arr[i];
    }

    delete[] arr; //deallocate old values
    arr = newArr; //assign pointer to new memory
    return *this; //return a self-reference
}
HeapArray& HeapArray::operator= (HeapArray&& tomove){ //move
    if(this != &tomove){ //dont move if passed self
        arraySize = tomove.arraySize; //copy size
        delete[] arr; //deallocate old memory
        arr = tomove.arr; //reset array pointer

        tomove.arr = nullptr; //empty HeapArray param
        tomove.arraySize = 0;
    }
    return *this; //return a self-reference
}

//subscript operator
int& HeapArray::operator[] (int i){
    return arr[i];
}

//member functions
int HeapArray::size() const {
    return arraySize;
}
int* HeapArray::begin() {
    return arr;
}
int* HeapArray::end(){
    return arr + arraySize;
}