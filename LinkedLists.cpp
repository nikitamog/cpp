
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  demonstrate some properties of linked lists.
*/

#include <stdexcept>
#include "LinkedLists.h"

using namespace std;

// constructors/destructors
template <typename T>
Node<T>::Node(Node<T>& p,
              T& d,
              Node<T>& n)
    :prev{p},data{d},next{n}{}

template <typename T>
Node<T>::Node(T& d) {
    Node(NULL,d,NULL);
}

template <typename T>
Node<T>::~Node<T>()
{
    delete data;
}
//============================================
// operators
//============================================
template <typename T>
Node<T> Node<T>::operator=(Node<T>& n)
{
    this->data = n->data;
    return *this;
}

// arithmetic
template <typename T>
Node<T> Node<T>::operator+(Node<T>& n)
{
    this->data = this->data + n->data;
    return *this;
}

template <typename T>
Node<T> Node<T>::operator-(Node<T>& n)
{
    this->data = this->data - n->data;
    return *this;
}

template <typename T>
Node<T> Node<T>::operator*(Node<T>& n)
{
    this->data = this->data * n->data;
    return *this;
}

template <typename T>
Node<T> Node<T>::operator/(Node<T>& n)
{
    this->data = this->data / n->data;
    return *this;
}

template <typename T>
Node<T> Node<T>::operator%(Node<T>& n)
{
    this->data = this->data % n->data;
    return *this;
}
//============================================
//============================================
// CLASS: Linked List
//============================================
//============================================

template <typename T>
LinkedList<T>::~LinkedList() //destructor
{
    if (head == NULL) return;
    Node<T>* curr = head;
    Node<T>* next = curr->next;
    while(next != NULL)
    {
        delete *curr;
        curr = next;
        next = curr->next;
    }
    delete curr;
}
//============================================
// operators
//============================================

template <typename T>
Node<T> LinkedList<T>::operator[](int index) const
{
    int i = index;
    // check lower bound
    if (i < 0) throw out_of_range("Linked List");  
    Node<T>* curr = head;
    while (curr != NULL && i > 0)
    {
        curr = curr.next;
        --i;
    }  
    if (i > 0) throw out_of_range("Linked List");
    // check upper bound
    return *curr;
}
//============================================  
// methods
//============================================

template <typename T>
void LinkedList<T>::remove(int index)
{
    Node<T>* curr = &this[index];
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

template <typename T>
void LinkedList<T>::add(T* data, int index)
{
    // check append
    if (index == size)
    {
        add(data);
        return;
    }
    Node<T>* curr = &this[index];
    // check prepend.
    if (index == 0) head = curr;
    Node<T>* newnode = new Node<T>(curr,
                                   data,
                                   curr->next);
    curr->next = newnode;
}

template <typename T>
void LinkedList<T>::add(T* data)
{
    // last element
    Node<T>* newnode = new Node<T>(tail,
                                   data, NULL);
    if(head==NULL) head = newnode;
    tail = newnode;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template <typename T>
int LinkedList<T>::length() const
{
    int i = 0;
    Node<T>* curr = head;
    while(curr != NULL)
    {
        curr = curr->next;
        ++i;
    }
    return i;
}

template <typename T>
T* LinkedList<T>::front() const
{
    assert(head != NULL);
    return head->data;
}

template <typename T>
T* LinkedList<T>::last() const
{
    assert(head != NULL);
    return tail->data;
}

template <typename T>
void LinkedList<T>::insertFirst(T* data)
{
    this->add(data, 0);
}

template <typename T>
void LinkedList<T>::insertLast(T* data)
{
    this->add(data);
}
  
template <typename T>
int LinkedList<T>::size()
{
    return size;
}
