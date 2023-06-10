#include "HeapArray.h"

// ----- CONSTRUCTOR ----- //
HeapArray::HeapArray(const int size) {
	arraySize = size;                       // set array size property
	arr = new int[arraySize] {0};           // allocate memory on heap
}
HeapArray::HeapArray(const HeapArray& tocopy){
    arraySize = tocopy.arraySize; //copy size
    arr = new int[arraySize]; //allocate memory to heap

    for(int i = 0; i < arraySize; i++){ //copy array values
        arr[i] = tocopy.arr[i];
    }
}

// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

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

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return arraySize; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + arraySize; }