#include <iostream>

using namespace std;

main() {
  int a;
  
  cout << "'a = 5' evaluation: " << (a = 5) << endl;

  double b;

  a = b;

  cout << "int a after double b assignment: " << a << endl;

  char c = 'a';

  cout << "char c: " << c;
  
  c += 3;

  cout << " and char c += 3: " << c << endl;

}
