
/*
  @course: CS 300
  @instructor: Fatma Serce
  @author: Nikita Mogilevsky
  @description:
  Use dynamic memory for storing
  two integer variables and print
  their addresses
*/

#include <iostream>

using namespace std;

int main()
{
  int *a = new int;
  int *b = new int;

  cout << "Enter value of a: ";
  cin >> *a;

  cout << "Enter value of b: ";
  cin >> *b;

  cout << "Dereferenced value of ptrA is " << *a;
  cout << " and is stored in address " << &a;
  cout << endl;
  
  cout << "Dereferenced value of ptrB is " << *b;
  cout << " and is stored in address " << &b;
  cout << endl;
}
