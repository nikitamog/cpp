
#include <iostream>
#include "LinkedLists.h"

using namespace std;

int main()
{
    LinkedList::LinkedList<int>* L = new LinkedList<int>;
    int* x;
    *x = 1;

    *L.add(x);
    *x = 2;
    *L.add(x);
    *x = 3;
    *L.add(x);
    cout << *L << endl;
    return 0;
}
