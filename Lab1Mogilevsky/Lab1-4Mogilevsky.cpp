

/*
  @course: CS 300
  @instructor: Fatma Serce
  @author: Nikita Mogilevsky
  @description:
  Take in an int array size, their values
  and print them along with the max DYNAMICALLY.
*/
 
#include <iostream>

using namespace std;

int main()
{
  int *size = new int;
  
  cout << "Enter number of Values: ";
  cin >> *size;
  
  int *array = new int[*size];

  cout << "Please enter the values: ";
  
  //store
  cin >> array[0];
  // stores max value
  int *temp = new int;
  *temp = array[0]; 
  for (int i = 1; i < *size; ++i)
    {
      cin >> array[i];
      if (array[i] > *temp)
        {
          *temp = array[i];
        }
    }
  
  //print
  cout << "Numbers:";
  
  for (int i = 0; i < *size; ++i)
    {
      cout << " " << array[i];
    }
  cout << endl;  

  cout << "Max value is: " << *temp;
} // main
