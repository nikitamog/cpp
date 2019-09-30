

#include <iostream>

using namespace std;


struct Vector
{
  // some custom datatype
  int size;
  double* elements;
};

void vector_init(Vector& v, int size)
{
  v.elements = new double[size];
  v.size = size;
}

main()
{
  Vector v;
  int s = 5; // size
  vector_init(v, s);
}

class VectorClass
{
public:
  // construct a vector
  VectorClass(int s):elements{new double[s]}, sz{s}{}
  // define accessor
  double& operator[](int i){return elements[i];}

  int size(){return sz;}
private:
  double* elements;
  int sz;
};
