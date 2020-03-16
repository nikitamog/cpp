#ifndef STACKADT_H
#define STACKADT_H

/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description: an abstract datatype with
  all the usual stack behavior: push,
  pop, etc.
 */

template<class T>
class StackADT
{
public:
    virtual T push(const T&) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif
