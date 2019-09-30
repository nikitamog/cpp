
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@gmail.com
 */

#include <iostream>
#include <string>

using namespace std;

main() {
  
  int a = 32, *ptr = &a;

  char ch = 'A', &cho = ch;
  
  cho += a;
  
  *ptr += ch;

  cout << a << ", " << ch << endl;
  
}
