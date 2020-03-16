
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  an array implementation of the stack
  abstract data type.
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackADT.h"
#include <stdexcept>

using namespace std;

template<class T>
class ArrayStack : public StackADT<T>
{
    int stop, size;
    T* stack;

public:
    // ArrayStack():stop{0},stack{new T[100]}{}
    ArrayStack(int size = 0):size{size}, stop{0}, stack{new T[size]}{}
    ~ArrayStack(){ delete stack; }
    void push(const T&);
    void pop();
    T top();
    bool isEmpty();
    bool isFull();
};

template <class T>
void ArrayStack<T>::push(const T& rData)
{
    if(stop == size) throw out_of_range("Stack is full.");

    stack[stop] = rData;
    stop++;
}

template <class T>
void ArrayStack<T>::pop()
{
    if(stop <= 0) throw domain_error("Nothing to pop");
    stack[stop-1] = 0;
    stop--;
    // alternatively, *stack[--stop] = 0;
}

template <class T>
T ArrayStack<T>::top()
{
    if(stop <= 0) throw  domain_error("Nothing to peek at.");
    return stack[stop-1];
}

template <class T>
bool ArrayStack<T>::isEmpty()
{
    return stop == 0;
}

template <class T>
bool ArrayStack<T>::isFull()
{
    return stop == size;
}

#endif
