#ifndef MURACH_MYVECTOR_H
#define MURACH_MYVECTOR_H

template <typename T>
class MyVector {
    private: 
        T* elem = nullptr;
        std::size_t arraySize;
        std::size_t space;

    public:
        //member types
        using size_type = std::size_t;
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;

        //constructors
        MyVector(){ //default
            elem = nullptr;
            arraySize = 0;
            space = 0;
        }
        MyVector(const MyVector& toCopy); //copy constructor
        MyVector(MyVector&& toMove); //move constructor
        MyVector(int initialSize); //set initial size
        MyVector(std::initializer_list<T> list); //initialization list

        //deconstructor
        ~MyVector();

        //assignment operator
        MyVector& operator=(const MyVector& toCopy); //copy assignment
        MyVector& operator=(MyVector&& toMove); //move assignment

        //subscript operator
        reference operator[](int i){
            return elem[i];
        }
        const_reference operator[](int i) const {
            return elem[i];
        }

        //member function
        size_type size() const {return arraySize;}
        size_type capacity() const {return space;}

        reference at(int index);
        const_reference at(int index) const;

        void reserve(int newSize);
        void push_back(T val);
        void resize(int newSize);

        iterator begin() {
            return elem;
        }
        const_iterator cbegin() const {
            return elem;
        }
        iterator end() {
            return elem + arraySize;
        }
        const_iterator cend() const {
            return elem + arraySize;
        }
};

#endif 