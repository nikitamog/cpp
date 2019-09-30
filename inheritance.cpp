
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  some space to explore and demonstrate inheritance.
 */

#include <iostream>

using namespace std;

class Parent
{
protected:
  int a, b;
public:
  Parent(int n = 0, int m = 0):a{n},b{m}{}
};

class Child : public Parent
{
public:
  Child (int n = 0, int m = 0) : Parent(n,m) {}
  const int getA(){return a;}
  const int getB(){return b;}
};

main()
{
  Child Foo;
  //printf("%i", Foo.getA());
  cout << Foo.getA();
}
