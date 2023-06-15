#include "MyList.h"

using namespace std;

template<typename T>
MyList<T>::~MyList(){ //deallocate memory for each element in the list
    Link<T>* iter; //traverse the list
    Link<T>* next; //to point to the next link in the list

    iter = head;
    while(iter){ //while iter != nullptr
        next = iter->next;
        delete iter;
        iter = next;
    }
}

//push_back()
template<typename T>
void MyList<T>::push_back(T item){
    Link<T>* newLink = new Link<T>(item); //allocate memory

    if(!head){
        head = newLink;
        tail = newLink;
    } else {
        auto currTail = tail;

        currTail->next = newLink;
        newLink->prev = currTail;

        tail = newLink;
    }
    ++listSize;
}

//pop_back()
template<typename T>
void MyList<T>::pop_back(){
    if(tail){
        if(head == tail){
            delete head;
            initialize();
        } else {
            Link<T>* toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete toDelete;
            --listSize;
        }
    }
}

//at()
template<typename T>
typename MyList<T>::reference MyList<T>::at(int index){
    if(index < 0 || index >= listSize){
        throw out_of_range("MyLinkedList<T>::at() - out of range");
    } else {
        Link<T>* iter = head; //start at first link
        for(int i = 0; i < index; ++i){ //iterate to desired link
            iter = iter->next;
        }
        return iter->value; //return value of link
    }
}

//remove()
template<typename T>
void MyList<T>::remove(T val){
    Link<T>* iter = head; //pointer to traverse list

    while(iter){
        if(iter->value == val){
            if(head == tail){ //if only one link
                delete head;
                initialize();
                break;
            } else { //if multiple links
                //rearrange connecting pointers
                if(iter == head){ //if first of multiple links
                    head = iter->next;
                    head->prev = nullptr;
                } else if (iter == tail){ //if last of multiple links
                    tail = iter->prev;
                    tail->next = nullptr;
                } else { //if between other links
                    //get the links before and after the current link
                    auto beforeIter = iter->prev;
                    auto afterIter = iter->next;

                    //connect before and after links to each other
                    beforeIter->next = afterIter;
                    afterIter->prev = beforeIter;
                }
                //remove current link
                Link<T>* next = iter->next; //store next element in the link
                delete iter; //deallocate memory
                iter = next; //move to next link 
                --listSize; //decrement size
            }
        } else { //current element doesn't match
            iter = iter->next; //move to next link
        }
    }
}