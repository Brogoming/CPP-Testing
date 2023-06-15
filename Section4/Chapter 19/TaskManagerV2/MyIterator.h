#ifndef MURACH_MYITERATOR_H
#define MURACH_MYITERATOR_H
#include "Link.h"

template<typename T>
class MyIterator{
    private:
        Link<T>* current = nullptr;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using reference = int&;
        using pointer = int*;

        //constructor
        MyIterator(Link<T>* curr){
            current = curr;
        }

        //operators
        MyIterator& operator=(const MyIterator& toCopy){ //assignment
            current = toCopy.current;
            return *this;
        }

        T& operator*() const { //indirection
            return current -> value;
        }

        bool operator==(const MyIterator& other) const { //equal
            return current = other.current;
        }

        bool operator!=(const MyIterator& other) const { //not equal
            return current != other.current;
        }

        MyIterator& operator++(){ //increment-prefix
            current = current->next;
            return *this;
        }

        MyIterator operator++(int unused){ //increment-postfix
            auto temp = *this;
            current = current->next;
            return temp;
        }

        MyIterator& operator--(){ //decrement-prefix
            current = current->prev;
            return *this;
        }

        MyIterator operator--(int unused){ //decrement-postfix
            auto temp = *this;
            current = current->prev;
            return temp;
        }
};

#endif