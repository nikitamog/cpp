#include <iostream>

using namespace std;

class Foo
{
public:
  
  Foo(){} // constructor
  static void toString()
  {
    cout << "hi" << endl;
  }
}; // Foo


main()
{
  Foo::toString(); // only if static.
}
