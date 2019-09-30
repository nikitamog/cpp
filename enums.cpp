#include <iostream>

using namespace std;

enum class Color {red, blue, green, cyan};
enum class Traffic_light {red, yellow, green};

Traffic_light& operator++(Traffic_light& t)
// prefix increment
{
  switch(t)
  {
  case Traffic_light::green: return t=Traffic_light::yellow;
  case Traffic_light::yellow: return t=Traffic_light::red;
  case Traffic_light::red: return t=Traffic_light::green;
  }
}
      
  
main()
{

  
  Traffic_light tl = Traffic_light::red;
  cout << "typeid: Traffic_light: " << typeid(tl).name() << endl;
  cout << "type value: " << tl << endl;
  cout << "typeid: ++Traffic_light: "<< typeid(++tl).name() << endl;
  cout << "type value: " << tl << endl;
  
}
