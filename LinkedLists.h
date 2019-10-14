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
    // bool operator!=( T&);
    Node<T>(T& rData);
    Node<T>(Node<T>* pPrev, T& rData, Node<T>* pNext);
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
    LinkedList(const LinkedList&); // copy constructor
    ~LinkedList(); //destructor

    bool isEmpty() const;
    int length() const;
    T* front() const;
    T* last() const;
    void remove(int index);
    int search(T& rData);
    void add(T& rData, int index);
    void add(T& rData); // appends data
    void insertFirst(T& rData);
    void insertLast(T& rData);
    Node<T>& operator[](int index) const;  
    LinkedList& operator=(const LinkedList&);
    
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
Node<T>::Node(Node<T>* _pPrev,
              T& _rData,
              Node<T>* _pNext)
    :pPrev(_pPrev),Data(_rData),pNext(_pNext){}

template <class T>
Node<T>::Node(T& rData) {
    Node(NULL,rData,NULL);
}

template <class T>
Node<T>::~Node<T>()
{
}
//============================================
// operators
//============================================
template <class T>
Node<T> Node<T>::operator=(Node<T>& rN)
{
    this->Data = rN.Data;
    return *this;
}

// arithmetic
template <class T>
Node<T> Node<T>::operator+(Node<T>& rN)
{
    this->Data = this->Data + rN.Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator-(Node<T>& rN)
{
    this->Data = this->Data - rN.Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator*(Node<T>& rN)
{
    this->Data = this->Data * rN.Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator/(Node<T>& rN)
{
    this->Data = this->Data / rN.Data;
    return *this;
}

template <class T>
Node<T> Node<T>::operator%(Node<T>& rN)
{
    this->Data = this->Data % rN.Data;
    return *this;
}

// streams
template<class U>
ostream& operator<<(ostream& rOStream, const Node<U>& rNode)
{
    rOStream<<rNode.Data<<endl;
    
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
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    Node<T>* curr = other.pHead;
    while(curr)
    {
        this->add(curr->Data);
        curr = curr->pNext;
    }
}

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
    Node<T>* temp = &(*this)[index];
    Node<T>* pCurr =temp;
    
    if (index == 0)
    {
        pHead = pCurr->pNext;
        delete pCurr;
        size--;
        return;
    }
    
    if (index == size) pTail = pCurr->pPrev;
    
    pCurr->pPrev->pNext = pCurr->pNext;
    pCurr->pNext->pPrev = pCurr->pPrev;

    delete pCurr;
    size--;
}

template <class T>
void LinkedList<T>::add(T& rData, int index)
{
    /* Adds an element to the list at the
       specified index. One may not add
       indeces that do not exist. */
    // check append
    if(index>size || index<0) return;

    if(index == 0){
        Node<T>* newnode = new Node<T>(NULL, rData, NULL);
        pHead->pPrev = newnode;
        newnode->pNext = pHead;
        pHead = newnode;
        if(pTail==NULL){
            pTail = pHead;
        }
        
    }
    else if (index == size)
    {
        add(rData);
    }
    else{


        Node<T>* temp = &(*this)[index];
        Node<T>* pCurr = temp;

        // Alternative way:
        // Node<T>* temp = pHead;
        // while(--index){
        //     temp = temp->pNext;
        // }

        Node<T>* newnode = new Node<T>(NULL, rData, NULL);
        newnode->pNext = temp->pNext;
        newnode->pPrev = temp;
        temp->pNext->pPrev = newnode;
        temp->pNext = newnode;

    }
    size++;
}

template <class T>
void LinkedList<T>::add(T& rData)
{
    /* Prepends and element to the list. */
    // last element
    Node<T>* newnode = new Node<T>(pTail,
                                   rData, NULL);
    if(pHead==NULL) 
        pHead = newnode;
    else 
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
void LinkedList<T>::insertFirst(T& rData)
{
    this->add(rData, 0);
}

template <class T>
void LinkedList<T>::insertLast(T& rData)
{
    this->add(rData);
}

template <class T>
int LinkedList<T>::search(T& rData)
{
    Node<T>* pCurr = pHead;
    if (!pHead) throw domain_error("List is Empty");
    int index = 0;

    while(pCurr)
    {
        if(pCurr->Data == rData)
            return index;
        pCurr = pCurr->pNext;
        index++;
    }

    // no matches
    throw invalid_argument("no such element");
    return index;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rOther)
{

    Node<T>* pCurr = pHead;
    Node<T>* pOCurr = rOther.pHead;
    
    // assume equal sizes
    while (pCurr != NULL && pOCurr != NULL)
    {
        pCurr->Data = pOCurr->Data;
        pCurr = pCurr->pNext;
        pOCurr = pOCurr->pNext;
    }

    // either done or sizes != equal
    // check this.size > other.size
    Node<T>* pPrev;

    // delete leftover pointers
    while(pCurr != NULL) {
        pPrev = pCurr;
        pCurr = pCurr->pNext;
        delete prev;
        size--;
    }

    // check this.size < other.size
    while(pOCurr != NULL) {
        add(pOCurr->Data);
        pOCurr = pOCurr->pNext;
        size++;
    }

    return *this;
}
        
    

template <class U>
ostream& operator<<(ostream& rOStream,
                    const LinkedList<U>& rList)
{
    //check empty
    
    if (rList.size == 0)
    {
        rOStream << "[]" << endl;
        return rOStream;
    }
    
    rOStream << "[";
    Node<U>* pNewNode = rList.pHead;

    while(pNewNode != NULL)
    {
        rOStream << pNewNode->Data << " ";
        pNewNode = pNewNode->pNext;
    }
    rOStream << "]";
    return rOStream;
}
        

#endif
