
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  Implements the QUEUEADT with an
  array.
 */

#include <stdexcept>
#include "QueueADT.h"

using namespace std;

template <class T>
class ArrayQueue : public QueueADT<T>
{
    T* list;
    int first, last, size;
    
public:
    ArrayQueue(int size = 100)
        :list{new T[size]},
         first{0},
         last{0},
         size{size}{}
    ~ArrayQueue() {delete[] list;}
    T enqueue(const T&);
    T dequeue();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

template <class T>
bool ArrayQueue<T>::isEmpty() const
{
    return list[first];
}

template <class T>
bool ArrayQueue<T>::isFull() const
{
    return (first + last) == (size - 1) || list[first];
}


template <class T>
T ArrayQueue<T>::enqueue(const T& data)
{
    // FIFO. last is pushed up
    if(first + last >= size - 1)
        throw out_of_range("list is full");    
    // update last if not empty
    if(!isEmpty())
    {
        last = (last + 1) % size;
    }
    
    return list[last] = data;
}

template <class T>
T ArrayQueue<T>::dequeue()
{
    /* removes the first 
       element and returns in the 
       list. Returns NULL if empty. */

    // check empty.
    if(!isEmpty()) {
        // save for return
        T data = list[first];
    
        // deallocate address
        list[first] = NULL;

        // update first
        first = (first + 1) % size;
        return data;
    }
    
    // list is empty
    throw length_error("No Elements.");
}

template <class T>
T ArrayQueue<T>::peek() const
{
    return list[first];
}

#endif
