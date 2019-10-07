
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  demonstrate some properties of linked lists.
*/

#include <stdexcept>
#include <iostream>
#include "LinkedLists.h"

using namespace std;

//============================================
//============================================
// NODE
//============================================
//============================================

// constructors/destructors
template <class T>
Node<T>::Node(Node<T>& rPrev,
              T& rData,
              Node<T>& rNext)
    :pPrev{rPrev},pData{rData},pNext{rNext}{}

template <class T>
Node<T>::Node(T& rData) {
    Node(NULL,rData,NULL);
}

template <class T>
Node<T>::~Node<T>()
{
    delete pData;
}
//============================================
// operators
//============================================
template <class T>
Node<T> Node<T>::operator=(Node<T>& rN)
{
    this->pData = rN->pData;
    return *this;
}

// arithmetic
template <class T>
Node<T> Node<T>::operator+(Node<T>& rN)
{
    this->pData = this->pData + rN->pData;
    return *this;
}

template <class T>
Node<T> Node<T>::operator-(Node<T>& rN)
{
    this->pData = this->pData - rN->pData;
    return *this;
}

template <class T>
Node<T> Node<T>::operator*(Node<T>& rN)
{
    this->pData = this->pData * rN->pData;
    return *this;
}

template <class T>
Node<T> Node<T>::operator/(Node<T>& rN)
{
    this->pData = this->pData / rN->pData;
    return *this;
}

template <class T>
Node<T> Node<T>::operator%(Node<T>& rN)
{
    this->pData = this->pData % rN->pData;
    return *this;
}

// streams
template<class U>
ostream& operator<<(ostream& rOStream, const Node<U>& rNode)
{
    cout << rNode->pData;
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
        delete *pCurr;
        pCurr = pNext;
        pNext = pCurr->pNext;
    }
    delete pCurr;
}
//============================================
// operators
//============================================

template <class T>
Node<T> LinkedList<T>::operator[](int index) const
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
    Node<T>* pCurr = &this[index];
    if (index == 0)
    {
        pHead = pCurr->pNext;
        delete pCurr;
        return;
    }
    if (index == size) pTail = pCurr->pPrev;
    pCurr->pPrev->pNext = pCurr->pNext;
    pCurr->pNext->pPrev = pCurr->pPrev;
    delete pCurr;
    size--;
}

template <class T>
void LinkedList<T>::add(T* pData, int index)
{
    /* Adds an element to the list at the
       specified index. One may not add
       indeces that do not exist. */
    // check append
    if (index == size)
    {
        add(pData);
        return;
    }
    Node<T>* pCurr = &this[index];
    // check prepend.
    if (index == 0) pHead = pCurr;
    Node<T>* newnode = new Node<T>(pCurr->pPrev,
                                   pData,
                                   pCurr);
    pCurr->pPrev = newnode;
}

template <class T>
void LinkedList<T>::add(T* pData)
{
    /* Prepends and element to the list. */
    // last element
    Node<T>* newnode = new Node<T>(pTail,
                                   pData, NULL);
    if(pHead==NULL) pHead = newnode;
    pTail = newnode;
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
    return pHead->pData;
}

template <class T>
T* LinkedList<T>::last() const
{
    assert(pHead != NULL);
    return pTail->pData;
}

template <class T>
void LinkedList<T>::insertFirst(T* pData)
{
    this->add(pData, 0);
}

template <class T>
void LinkedList<T>::insertLast(T* pData)
{
    this->add(pData);
}

template <class U>
ostream& operator<<(ostream& rOStream,
                    const LinkedList<U>& rList)
{
    cout << "[";
    Node<U>* pNewNode = rList->pHead;
    for(int i = 0; i < rList->size - 1; ++i)
    {
        cout << pNewNode << ", ";
        pNewNode = pNewNode->pNext;
    }
    cout << pNewNode << "]" << endl;
    return rOStream;
}
        
