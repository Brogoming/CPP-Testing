#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

template<typename T>
class HeapArray {
private:
	int arraySize;
	T* arr;

public:
	// constructor
	HeapArray(const int);
	HeapArray(const HeapArray& tocopy); //copy constructor
	HeapArray(HeapArray&& tomove); //move constructor

	// destructor
	~HeapArray();

	// subscript operator 
	T& operator[] (int i) {return arr[i];}

	//assignment operator
	HeapArray& operator= (const HeapArray& tocopy); //copy assignment
	HeapArray& operator= (HeapArray&& tomove); //move assignment

	// Member functions
	int size() const {return arraySize;}
	T* begin() {return arr;}
	T* end() { return arr + arraySize;}
};

// ----- CONSTRUCTORS ----- //
template<typename T>
HeapArray<T>::HeapArray(const int size) {
	arraySize = size;                       // set array size property
	arr = new T[arraySize];           // allocate memory on heap
	for(int i = 0; i < arraySize; i++){ //initalize array values
        arr[i] = T();
    }
}

template<typename T>
HeapArray<T>::HeapArray(const HeapArray& tocopy){  //copy
    arraySize = tocopy.arraySize; //copy size
    arr = new T[arraySize]; //allocate memory to heap

    for(int i = 0; i < arraySize; i++){ //copy array values
        arr[i] = tocopy.arr[i];
    }
}

template<typename T>
HeapArray<T>::HeapArray(HeapArray&& tomove){  //move
    arraySize = tomove.arraySize; //copy size
    arr = tomove.arr; //reset array pointer
	tomove.arraySize = 0; //empty passed in container
	tomove.arr = nullptr;
}

// ----- DESTRUCTOR ----- //
template<typename T>
HeapArray<T>::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

//assignment operators
template<typename T>
HeapArray<T>& HeapArray<T>::operator= (const HeapArray& tocopy){ //copy
    arraySize = tocopy.arraySize; //copy size
    int* newArr = new int[arraySize]; //allocate memory to heap

    for(int i = 0; i < arraySize; ++i){ //copy array values
        newArr[i] = tocopy.arr[i];
    }

    delete[] arr; //deallocate old values
    arr = newArr; //assign pointer to new memory
    return *this; //return a self-reference
}

template<typename T>
HeapArray<T>& HeapArray<T>::operator= (HeapArray&& tomove){ //move
    if(this != &tomove){ //don't move if passed self
		arraySize = tomove.arraySize; //copy size
		delete[] arr; //deallocate old memory
		arr = tomove.arr; //reset array pointer
		tomove.arraySize = 0; //empty passed in container
		tomove.arr = nullptr; 
	}
	return *this; // return a self-reference
}

#endif /* MURACH_HEAPARRAY_H */
