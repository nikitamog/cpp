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

template <class T>
struct Node
{
    // some generic type for data.
    T* pData;

    Node<T>* pNext;
    Node<T>* pPrev;

public:
    // arithmetic operators
    // for sorting methods, maybe.
    Node<T> operator=(Node<T>& rN);
    Node<T> operator+(Node<T>& rN);
    Node<T> operator-(Node<T>& rN);
    Node<T> operator*(Node<T>& rN);
    Node<T> operator/(Node<T>& rN);
    Node<T> operator%(Node<T>& rN);

    Node<T>(T& rData);
    Node<T>(Node<T>& rPrev, T& pData, Node<T>& rNext);
    ~Node<T>();

    // streams
    template <class U>
    friend ostream& operator<<(ostream& rOStream, const Node<U>& rNode);
    
}; //Node

template <class T>
class LinkedList // singley linked
{
    // private by default.
    Node<T>* pHead;
    Node<T>* pTail;
    int size; // update length

public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor

    bool isEmpty() const;
    int length() const;
    T* front() const;
    T* last() const;
    void remove(int index);
    void add(T* pData, int index);
    void add(T* pData); // appends data
    void insertFirst(T* pData);
    void insertLast(T* pData);
    Node<T> operator[](int index) const;  

    template <class U>
    friend ostream& operator<<(ostream& rOStream,
                               const LinkedList<U>& rList);
}; // Linked List

#endif
