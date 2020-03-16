
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  test the functionality of QueueADT
  implementations.
*/

#include "QueueADT.h"
#include "LinkedQueue.h"
#include "ArrayQueue.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedQueue<int> links;
    ArrayQueue<int> arr;

    cout << "Links Queue: " << endl;
    cout << "enqueue 5: " << links.enqueue(5) << endl;
    cout << "peek: " << links.peek() << endl;
    cout << "enqueue 6: " << links.enqueue(6) << endl;
    cout << "peek: " << links.peek() << endl;
    cout << "dequeue: " << links.dequeue() << endl;
    cout << "peek: " << links.peek() << endl;
    
    return 0;
}
