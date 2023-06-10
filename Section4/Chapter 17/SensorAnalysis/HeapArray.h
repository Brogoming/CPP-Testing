#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

class HeapArray {
private:
	int arraySize;
	int* arr = nullptr;

public:
	// constructor
	HeapArray(const int);
	HeapArray(const HeapArray& tocopy); //copy constructor

	// destructor
	~HeapArray();

	// subscript operator 
	int& operator[] (int i);

	//assignment operator
	HeapArray& operator= (const HeapArray& tocopy); //copy assignment

	// Member functions
	int size() const;
	int* begin();
	int* end();
};

#endif /* MURACH_HEAPARRAY_H */
