
/*
  @course: CS 300
  @instructor: Fatma Serce
  @author: Nikita Mogilevsky
  @description:
  Implements a point class with setter
  and getter methods.
*/

#include <iostream>

using namespace std;

class Point {
  int x, y;

public:
  Point(int n = 0, int m = 0):x{n},y{m}{}
  void setX(int n){x = n;}
  void setY(int n){y = n;}
  const int getX(){return x;}
  const int getY(){return y;}
  Point operator+(Point n) {
    x += n.getX();
    y += n.getY();
    return *this;
  }
};

int main()
{
  Point *p1 = new Point;
  Point *p2 = new Point(2);
  Point *p3 = new Point(2,3);
  cout << "p1 x: " << p1->getX() << endl;
  p2->setX(4);
  cout << "p2 x: " << p2->getX() << endl;
  p3->setY(10);
  cout << "p3 y: " << p3->getY() << endl;

  Point* p4 = new Point;
  *p4 = *p2 + *p3;

  cout << "p4 x: " << p4->getX() << endl;
  return 0;

  // clean up
  delete p1, p2, p3, p4;
  p1 = NULL;
  p2 = NULL;
  p3 = NULL;
  p4 = NULL;
}
