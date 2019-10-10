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
#include <iostream>

using namespace std;

template <class T>
struct Node
{
    // some generic type for data.
    T Data;

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

    Node<T>(T Data);
    Node<T>(Node<T>* pPrev, T Data, Node<T>* pNext);
    // ~Node<T>();

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
    void add(T Data, int index);
    void add(T Data); // appends data
    void insertFirst(T Data);
    void insertLast(T Data);
    void printReverse();
    Node<T>& operator[](int index) const;  

    template <class U>
    friend ostream& operator<<(ostream& rOStream,
                               const LinkedList<U>& rList);
}; // Linked List

// IMPLEMENTATIONS

//============================================
//============================================
// NODE
//============================================
//============================================

// constructors/destructors
template <class T>
Node<T>::Node(Node<T>* pPrev,
              T Data,
              Node<T>* pNext)
    :pPrev{pPrev},Data{Data},pNext{pNext}{}

template <class T>
Node<T>::Node(T Data) {
    Node(NULL,Data,NULL);
}

/*
template <class T>
Node<T>::~Node<T>()
{
}
*/

//============================================
// operators
//============================================
template <class T>
Node<T> Node<T>::operator=(Node<T>& rN)
{
    this->Data = rN->Data;
    return *this;
}

// arithmetic
template <class T>
Node<T> Node<T>::operator+(Node<T>& rN)
{
    this->Data = this->Data + rN->Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator-(Node<T>& rN)
{
    this->Data = this->Data - rN->Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator*(Node<T>& rN)
{
    this->Data = this->Data * rN->Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator/(Node<T>& rN)
{
    this->Data = this->Data / rN->Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator%(Node<T>& rN)
{
    this->Data = this->Data % rN->Data;
    return *this;
}

// streams
template<class U>
ostream& operator<<(ostream& rOStream, const Node<U>& rNode)
{
    // if(!rNode)
    // {
    //     cout << "NULL";
    //     return rOStream;
    //     }
    
    cout << rNode.Data;
    return rOStream;
}
    
//============================================
//============================================
// END NODE
//============================================
//============================================
// CLASS: Linked List
//============================================
//============================================

template <class T>
LinkedList<T>::LinkedList()
    :pHead{NULL}, pTail{NULL}, size{0}{}

template <class T>
LinkedList<T>::~LinkedList() //destructor
{
    if (pHead == NULL) return;
    Node<T>* pCurr = pHead;
    Node<T>* pNext = pCurr->pNext;
    while(pNext != NULL)
    {
        delete pCurr;
        pCurr = pNext;
        pNext = pCurr->pNext;
    }
    delete pCurr;
}
//============================================
// operators
//============================================

template <class T>
Node<T>& LinkedList<T>::operator[](int index) const
{
    int i = index;
    // check lower bound
    if (i < 0) throw out_of_range("Linked List");  
    Node<T>* pCurr = pHead;
    while (pCurr != NULL && i > 0)
    {
        pCurr = pCurr->pNext;
        --i;
    }
    
    if (i > 0) throw out_of_range("Linked List");
    // check upper bound
    
    return *pCurr;
}
//============================================  
// methods
//============================================

template <class T>
void LinkedList<T>::remove(int index)
{
    if(index >= size || index < 0) throw out_of_range("Linked List");
    
    Node<T> temp = (*this)[index];
    Node<T>* pCurr = &temp;
    if(size == 1)
    {
        pHead = NULL;
        pTail = NULL;
        delete pCurr;
    }

    if (index == 0)
    {
        pHead = pCurr->pNext;
        if(pHead){
            pHead->pPrev = NULL;
        }
        delete pCurr;
        size--;
        return;
    }

    if (index == size-1) pTail = pCurr->pPrev;
    
    pCurr->pPrev->pNext = pCurr->pNext;
    pCurr->pNext->pPrev = pCurr->pPrev;

    delete pCurr;
    size--;
}

template <class T>
void LinkedList<T>::add(T Data, int index)
{
    /* Adds an element to the list at the
       specified index. One may add
       indices that do not exist. */
    if (index > size) throw out_of_range("Index too large.");
    
    // check append
    if (index == size || isEmpty())
    {
        add(Data);
        return;
    }

    Node<T> temp = (*this)[index];
    Node<T>* pCurr = &temp;

    Node<T>* newnode = new Node<T>(pCurr->pPrev,
                                   Data,
                                   &temp);

    // check if no prepend 
    if (pCurr->pPrev) pCurr->pPrev->pNext = newnode;
    pCurr->pPrev = newnode;

    size++;
}

template <class T>
void LinkedList<T>::add(T Data)
{
    /* Appends and element to the list. */
    
    if (size == 0)
    {
        // list is empty
        Node<T>* newnode = new Node<T>(Data);
        pHead = newnode;
        pTail = newnode;
        size++;
        return;
    }
    
    Node<T>* newnode = new Node<T>(pTail,
                                   Data, NULL);
    pTail->pNext = newnode;
    pTail = newnode;
    size++;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
    return pHead == NULL;
}

template <class T>
int LinkedList<T>::length() const
{
    /*
    int i = 0;
    Node<T>* pCurr = pHead;
    while(pCurr != NULL)
    {
        pCurr = pCurr->pNext;
        ++i;
    }
    return i;
    */
    return size;
}

template <class T>
T* LinkedList<T>::front() const
{
    assert(pHead != NULL);
    return pHead->Data;
}

template <class T>
T* LinkedList<T>::last() const
{
    assert(pHead != NULL);
    return pTail->Data;
}

template <class T>
void LinkedList<T>::insertFirst(T Data)
{
    this->add(Data, 0);
}

template <class T>
void LinkedList<T>::insertLast(T Data)
{
    this->add(Data);
}

template <class T>
void LinkedList<T>::printReverse()
{
    Node<T>* pCurr = pTail;
    if (!pCurr)
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << endl;

    while(pCurr->pNext)
    {
        cout << pCurr << ", ";
        pCurr = pCurr->pPrev;
    }
    cout << pCurr << "]" << endl;
    
}

template <class U>
ostream& operator<<(ostream& rOStream,
                    const LinkedList<U>& rList)
{
    //check empty
    
    if (rList.size == 0)
    {
        cout << "[]" << endl;
        return rOStream;
    }
    
    cout << "[";
    Node<U>* pNewNode = rList.pHead;
    for(int i = 0; i < rList.size - 1; ++i)     
    {                                           
        cout << *pNewNode << ", ";              
        pNewNode = pNewNode->pNext;             
    }
    // while(pNewNode != NULL)
    // {
    //     cout << pNewNode->Data << ", ";
    //     pNewNode = pNewNode->pNext;
    // }
    cout << *pNewNode << "]" << endl;
    cout << "size: " << rList.size << endl;
    return rOStream;
}
        

#endif
