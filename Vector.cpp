#include "Vector.h" // fetch interface

Vector::Vector(int s) //constructor
  :elem{new double[s]},sz{s}
{}

double& Vector::operator[](int i)
{
  //if (i < 0 || size()<=i) throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

int Vector::size()
{
  return sz;
}
