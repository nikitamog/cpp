
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  Implements a stack-based calculator
  that takes in user input.
*/

#include <iostream>
#include "LinkedStack.h"

void welcome()
{
    cout << "========================================" << endl;
    cout << "   Welcome to the Calculator Program!" << endl;
    cout << "========================================" << endl;
}

void farewell()
{
    cout << "========================================" << endl;
    cout << "    Thank you for using Calculator." << endl;
    cout << "========================================" << endl;
}
    
void printMenu()
{
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~ Legend ~~~~~~~~~~~~~~~~" << endl;
    cout << "   '\\' => Quit" << endl;
    cout << "   '+-*/%' => Operators" << endl;
    cout << "   '^' => Pop the stack" << endl;
    cout << "   Calculator accepts Integers." << endl;    
    cout << "~~~~~~~~~~~~~~ End Legend ~~~~~~~~~~~~~~" << endl;
}

string readString()
{
    /* Reads string from
       the user. */
    cout << "Enter an expression: ";
    string userString;
    cin >> userString;
    return userString;
}

LinkedStack<int> stack;

int main()
{
    // print welcome message
    welcome();
    
    printMenu();
    
    // user input loop
    char userChar;
    do
    {
        string userString = readString();

        int userNum; // for pushing to stack
        
        for(int i = 0; i < userString.length(); ++i)
        {
            userChar = userString[i];

            switch(userChar)
            {
                // ascii digit values [48,57]
            case 48 ... 57:
            {
                // userChar is a digit
                // load integer
                userNum = 0;

                for (int j = i; j < userString.length(); j++)
                {
                    if(userChar >= 48 || userChar <= 57)
                    {
                        userNum *= 10;
                        userNum += userString[j] - 48;
                    }
                    else
                    {
                        // continue along expression.
                        i = j;
                        userChar = userString[j];
                        break;
                    }
                }
                stack.push(userNum);
            }
            // operators
            case '+':
            {
                int result = 0;
                // top element is succeeding.
                if(!stack.isEmpty())
                    result += stack.pop();
                if(!stack.isEmpty())
                    result += stack.pop();
                cout << result << endl;
                stack.push(result);
                break; // search further along expression
            }
            case '-':
            {
                int result = 0;
                // subtracting succeeding element.
                if(!stack.isEmpty())
                    result -= stack.pop();
                if(!stack.isEmpty())
                    result += stack.pop();
                cout << result << endl;
                stack.push(result);
                break; // search further along expression
            }
            case '*':
            {
                int result = 0;
                // this is the multiplying factor.
                if(!stack.isEmpty())
                    result += stack.pop();
                // this is the result beforehand.
                if(!stack.isEmpty())
                    result *= stack.pop();
                cout << result << endl;
                stack.push(result);                
                break; // search further along expression
            }
            case '/':
            {
                int result = 0;
                // this is the denominator.
                if(!stack.isEmpty())
                    result += stack.pop();
                if(!stack.isEmpty())
                    result = stack.pop()/result;
                cout << result << endl;
                stack.push(result);                
                break; // search further along expression
            }
            case '%':
            {
                int result = 0;
                if(!stack.isEmpty())
                    result += stack.pop();
                if(!stack.isEmpty())
                    result = stack.pop()%result;
                cout << result << endl;
                stack.push(result);                
                break; // search further along expression
            }
            // print
            case '<':
            {
                if(i != userString.length() - 1 &&
                   userString[i+1] == '<')
                {
                    cout << stack << endl;
                    ++i;
                    break;
                }
            // pop a single element
            }
            case '^':
            {
                cout << stack.pop() << endl;
                break;
            }
            // exit
            case '\\':
            {
                // there must be a better way to do this
                cout << "result: " << stack.pop() << endl;
            }
            default:
            {
                cout << "Invalid input." << endl;
            }
            } // end switch
        } // for
            
    } while (userChar != '\\');
    
    // exit message
    farewell();
    return 0;
} // main
