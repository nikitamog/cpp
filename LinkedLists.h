#include <stdexcept>

using namespace std;

template <typename T>
struct Node
{
  Node<T>* prev;
  Node<T>* next;
  // some generic type for data.
  T* data;
  Node<T> operator=(Node<T>& n);
}; //Node

template <typename T>
class LinkedList
{
  Node<T>* head;
  Node<T>* tail;

  int size;

public:
  ~LinkedList(); //destructor

  void remove(int i);
  void add(Node<T>& n, int i);
  double operator[](int i);

  
}; // Linked List
