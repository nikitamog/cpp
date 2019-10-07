
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@gmail.com
 */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
  
  int a = 32, *ptr = &a, *redundant = &a;

  void* ref2ref = (void *)redundant;
  
  //  char ch = 'A', &cho = ch;
  
  //  cho += a;
  
  //  *ptr += ch;

  //  cout << a << ", " << ch << endl;

  cout << "ptr " << ptr << endl;
  cout << "redundant " << redundant << endl;

  cout << "redundant's value after delete" << ref2ref;
  delete ptr;

  if (ptr) throw domain_error("using ptr after delete");

  cout << "redundant after delete " << redundant << endl;
  

}
