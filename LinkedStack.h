#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@gmail.com
  @description:
  An implementation of the well-known
  queue datatype using linked nodes.
*/

#include "StackADT.h"
#include <iostream>
#include <stdexcept>

using namespace std; // for NULL, nullptr

template <class T>
struct node
{
    /* A single element with 
       double-linking.
     */
    T* data;
    node<T>* next;

public:
    // constructors
    node(const T& data,
            node<T>* next)
        :data{new T(data)},
         next{next}{}
    
    // copy constructor
    node(const node<T>& other)
        :data{new T(other.data)},
         next{other.next}{}
    /*
    // destructor
    ~node(){
        delete data;
    }
    */
}; // node

template <class T>
class LinkedStack : public StackADT<T>
{
    node<T>* head;

public:
    //constructor
    LinkedStack() : head{nullptr} {}
    // copy constructor
    LinkedStack(LinkedStack<T>& other);
    ~LinkedStack<T>();
    T push(const T&);
    T pop();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
    
    template <class U>
    friend ostream& operator<<(ostream& os, LinkedStack<U> L);
}; // LinkedStack

//======================================
// constructor
//======================================

template<class T>
LinkedStack<T>::LinkedStack(LinkedStack& other)
    :head{nullptr}
{
    // make auxillary stack
    LinkedStack<T> aux;
    while(!other.isEmpty())
    {
        T data = other.pop();
        aux.push(data);
    }
    
    // restore referenced instance
    // load current instance
    while(!aux.isEmpty())
    {
        T data = aux.pop();
        other.push(data);
        push(data);
    }
}

// destructor
template <class T>
LinkedStack<T>::~LinkedStack()
{
    while(!isEmpty())
    {
        pop();
    }
}

//======================================
// methods
//======================================

template<class T>
bool LinkedStack<T>::isEmpty() const {
    return head == nullptr;
}

template<class T>
T LinkedStack<T>::push(const T& data)
{
    head = new node<T>(data, head);
    return data;
}

template <class T>
T LinkedStack<T>::pop()
{
    if(isEmpty())
        throw length_error("list is empty");

    T data = *(head->data);
    node<T>* temp = head->next;
    delete head;
    head = temp;
    return data;
}

template <class T>
T LinkedStack<T>::peek() const
{
    return *head->data;
}

template <class T>
bool LinkedStack<T>::isFull() const
{
    return false;
}

template <class U>
ostream& operator<<(ostream& os, LinkedStack<U> L)
{
    /* pass by value makes a stack copy. */
    os << "<";

    while(!L.isEmpty())
    {
        os << L.pop();
        if(!L.isEmpty())
            os << ", ";
    }
    os << ">";
    return os;
}

#endif
