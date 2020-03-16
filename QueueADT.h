
#ifndef QUEUEADT_H
#define QUEUEADT_H
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  An abstract datatype definition of
  the common Queue. Comes with all
  the typical functionalities.
 */

template <class T>
class QueueADT
{
public:
    virtual T enqueue(const T&) = 0;
    virtual T dequeue() = 0;
    virtual T peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
}; // QueueADT

#endif
