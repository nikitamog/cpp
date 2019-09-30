/*
@author: Nikita Mogilevsky
@email: nikitamog@gmail.com

*/

#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

main()
{
  vector<int> a(3,2);
  a[0] = 5;
  a[1] = 4;
  a[2] = 3;

  for(int i = 0; i < 3; ++i)
    {
      printf("%i",a[i]);
    }

  printf("\n");
}
