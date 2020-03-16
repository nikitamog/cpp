 
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  A linked list impletmentation of
  stack behavior;
*/

#include "QueueADT.h"
#include <stdexcept>

using namespace std; // for NULL and nullptr

template <class T>
struct node {
    T* data;
    node<T> *next, *prev;
    // constructor
    node(const T& data,
            node<T>* next = nullptr,
            node<T>* prev = nullptr)
        :data{new T(data)},
         next{next},
         prev{prev}{}

    // copy constructor
    node(node<T>& other)
        :data{other.data},
         next{other.next},
         prev{other.prev}{}
    
    // destructor
    ~node() {delete data;}
};

template <class T>
class LinkedQueue : public QueueADT<T>
{
    node<T>* head, *tail;
    int size;

public:
    //constructor
    LinkedQueue()
        :size{0},
         head{nullptr},
         tail{nullptr}{}
    ~LinkedQueue(){}
    T enqueue(const T&);
    T dequeue();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
}; // LinkedQueue

template <class T>
bool LinkedQueue<T>::isEmpty() const
{
    return head == nullptr;
}

template <class T>
bool LinkedQueue<T>::isFull() const
{
    // consult your RAM
    // for better info.
    return false;
}

template <class T>
T LinkedQueue<T>::enqueue(const T& data)
{
    
    node<T>* newnode = new node<T>(data);

    // check empty
    if(size == 0)
    {
        head = newnode;
        tail = head;
        return data;
    }

    // queue is not empty.
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    size++;
    return data;
}

template <class T>
T LinkedQueue<T>::dequeue()
{
    // check empty
    if(isEmpty())
        throw out_of_range("No elements to dequeue");

    // list is not empty

    node<T>* temp = head;
    T data = *head->data;

    if(!head->next)
    {
        head = nullptr;
    }
    else
    {
        head = head->next;
    }

    --size;
    delete temp;
    return data;
}

template <class T>
T LinkedQueue<T>::peek() const
{
    return *head->data;
}

#endif
