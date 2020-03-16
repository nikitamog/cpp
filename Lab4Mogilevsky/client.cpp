
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  tests the functionality of the implemented
  StackADT by counting user-provided
  parentheses.
 */

#include "ArrayStack.h"
#include <iostream>

using namespace std;

string promptUserString()
{
    string str = "";
    cout << "Enter the input: ";
    cin >> str;
    return str;
}

bool isBalanced(string& userstr)
{
    /* returns whether there is a matching
       closed, brace for each open brace.
       only works for sizes up to 100.
     */

    int count = 0;

    ArrayStack<char>* tempStack = new ArrayStack<char>(userstr.size());


    for(int i = 0; i < userstr.size(); ++i)
    {
        if(userstr[i] == '(')
        {
            tempStack->push(userstr[i]);
        }
        else if(userstr[i] == ')')
        {
            if(tempStack->isEmpty()) {
                delete tempStack;
                return false;
            }
            // not empty
            tempStack->pop();
        }
    }
    bool result = tempStack->isEmpty();
    delete tempStack;
    return result;
}

int main()
{
    string str = promptUserString();
    if(isBalanced(str))
    {
        cout << "Balanced." << endl;
    }
    else {
        cout << "Unbalanced." << endl;
    }
    return 0;
    
}
