
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  demonstrate some properties of linked lists.
 */

#include <stdexcept>

using namespace std;

struct Node
{
  Node* prev;
  Node* next;
  // some generic type for data.
}; //Node

class LinkedList
{
  List<Node>* list;
public:

  ~LinkedList() //destructor
  {
    // delete data;
  }

  double operator[](int i);
}; // Linked List
