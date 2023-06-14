#include "MyVector.h"

using namespace std;

//copy constructor
template<typename T>
MyVector<T>::MyVector(const MyVector& toCopy){
    arraySize = toCopy.arraySize; //copy size
    space = toCopy.arraySize; //set capacity
    elem = new T{arraySize}; //allocate memory for the array

    //copy the elements of toCopy's array 
    for(int i = 0; i < arraySize; ++i){
        elem[i] = toCopy.elem[i];
    }
}

//move constructor
template<typename T>
MyVector<T>::MyVector(MyVector&& toMove){
    arraySize = toMove.arraySize; //copy size
    space = toMove.arraySize; //copy capacity
    elem = toMove.elem; //point to existing elements

    //empty the passed in vector
    toMove.arraySize = 0;
    toMove.space = 0;
    toMove.elem = nullptr;
}

//constructor that accepts an integer value for initial size
template<typename T>
MyVector<T>::MyVector(int initialSize){
    arraySize = space = initialSize; //set initial size and capacity
    elem = new T[arraySize]; //allocate memory for array

    //initialize the array with default value of type
    for(int i = 0; i < initialSize; ++i){
        elem[i] = T();
    }
}

//constructor that accepts an initalization list
template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> list){
    arraySize = space = list.size(); //set initial size and capacity
    elem = new T(arraySize); //allocate memory for array

    //copy the elements from the list 
    for(int i = 0; i < arraySize; ++i){
        elem[i] = list.begin()[i];
    } 
}

//deconstructor
template<typename T>
MyVector<T>::~MyVector(){
    delete[] elem; //ok even if elem is nullptr
}

//copy assignment
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& toCopy){
    arraySize = toCopy.arraySize; //copy size
    space = toCopy.arraySize; //set capacity

    //allocate new space
    T* newElem = new T[arraySize];

    //copy elements
    for(int i = 0; i < arraySize; ++i){
        newElemp[i] = toCopy.elem[i];
    }

    //deallocate old space
    delete[] elem;

    //assign new space
    elem = newElem;

    //return a self-reference
    return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& toMove){
    if(this != &toMove){
        arraySize = toMove.arraySize; //copy size
        space = toMove.space; //copy capacity

        //deallocate old space and then point to existing element
        delete[] elem;
        elem = toMove.elem;

        //empty the passed in vector
        toMove.arraySize = 0;
        toMove.space = 0;
        toMove.elem = nullptr;
    }

    //return a self-reference
    return *this;
}