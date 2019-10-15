
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> L;

    LinkedList<int>* pL = &L;
    LinkedList<int>& rL = L;

    cout << rL << endl;
    rL.printReverse();
    
    int a = 1;
    int &x = a;
    int* rA = &a;
    L.add(a);
    cout << rL << endl;
    rL.printReverse();
    int b = 2;
    int &rB = b;
    L.add(rB);
    int c = 3;
    int &rC = c;
    L.add(c);

    cout << rL << endl;

    cout << "rL length: " << rL.length() << endl;
    cout << "rL isEmpty: " << rL.isEmpty() << endl;
    cout << "rL[2]" << rL[2] << endl;
    cout << "Reverse rL: ";
    rL.printReverse();
    rL.add(rC, 2);
    cout << "rL add(c, 2). Printing rL[2]: " << rL[2] << endl;
    cout << "rL: " << rL << endl;
    rL.add(a);
    cout << "rL: " << rL << endl;
    rL.remove(1);
    cout << "rL remove(1): " << rL << endl;
    rL.insertFirst(c);
    cout << "rL insertFirst(c)" << rL  << endl;
    rL.insertLast(c);
    cout << "rL insertLast(c)" << rL << endl;
    
    
    
    return 0;
}
