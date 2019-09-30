
/*
  @course: CS 300
  @instructor: Fatma Serce
  @author: Nikita Mogilevsky
  @description:
  Takes a value of two variables and returns their
  vaues and stored addresses
 */

#include <iostream>

using namespace std;

int main()
{
  int a, b;

  printf("Enter the value of A: ");

  cin >> a;

  printf("Enter the value of B: ");

  cin >> b;

  int * ptrA, *ptrB;

  ptrA = &a;
  ptrB = &b;

  cout << "Value of ptrA is " << *ptrA;
  cout << " and stored in address " << ptrA;
  cout << endl;
  cout << "Value of ptrB is " << *ptrB;
  cout << " and stored in address " << ptrB;
  cout << endl;
}
