#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  * Stuff todo
  ** TODO update tail references in add and remove.
  */

#include <stdexcept>

using namespace std;

template <typename T>
struct Node
{
    // some generic type for data.
    T* data;

    Node<T>* next;
    Node<T>* prev;

    // arithmetic operators
    // for sorting methods, maybe.
    Node<T> operator=(Node<T>& n);
    Node<T> operator+(Node<T>& n);
    Node<T> operator-(Node<T>& n);
    Node<T> operator*(Node<T>& n);
    Node<T> operator/(Node<T>& n);
    Node<T> operator%(Node<T>& n);

    Node<T>(T& d); // d for data
    Node<T>(Node<T>& prev, T& data, Node<T>& next);
    ~Node<T>();
    
public:   
    // streams
    template <typename U>
    friend ostream& operator<<(ostream& o, Node<U> const &node);
    
}; //Node

template <typename T>
class LinkedList // singley linked
{
    // private by default.
    Node<T>* head;
    Node<T>* tail;
    int size; // update length

public:
    ~LinkedList(); //destructor

    bool isEmpty() const;
    int length() const;
    T* front() const;
    T* last() const;
    void remove(int index);
    void add(T* data, int index);
    void add(T* data); // appends data
    void insertFirst(T* data); // TODO
    void insertLast(T* data); // TODO
    Node<T> operator[](int index) const;  
  
}; // Linked List

#endif
