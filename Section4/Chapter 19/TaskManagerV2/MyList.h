#ifndef MURACH_MYLIST_H
#define MURACH_MYLIST_H
#include "MyIterator.h"

template<typename T>
class MyList {
    private:
        Link<T>* head; //pointer to the first link in the list
        Link<T>* tail; //pointer to the last link in the list
        std::size_t listSize; //number of nodes in the list

        //helper function
        void initialize(){
            head = nullptr;
            tail = nullptr;
            listSize = 0;
        }

    public:
        //member types
        using size_type = std::size_t;
        using value_type = T;
        using reference = T&;
        using iterator = MyIterator<T>;

        //constructor
        MyList(){
            initialize();
        }

        //destructor
        ~MyList();

        //member functions
        size_type size() const {
            return listSize;
        }
        void push_back(T);
        void pop_back();
        reference at(int index);
        void remove(T);

        iterator begin(){
            return iterator(head);
        }
        iterator end(){
            return iterator(nullptr);
        }
};

#endif