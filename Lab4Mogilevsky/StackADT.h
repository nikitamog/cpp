
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  an abstract datatype begrudgingly transcribed from
  the professor's handout.
 */

#ifndef STACK_ADT_H
#define STACK_ADT_H

template <class T>
class StackADT
{
    virtual void push(const T&) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

#endif
