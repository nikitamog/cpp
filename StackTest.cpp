
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  Tests the features and implementations
  the Stack abstract data type.
*/

#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> s;
    s.push(2);
    s.push(3);
    s.push(6);
    
    cout << s << endl;
    return 0;
}
