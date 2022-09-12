#include <iostream>
#include <string>

using namespace std;

string infixToPostfix(string infix)
{
    return infix;
}

bool isOperator(char character)
{
    if (character == '^' || character == '/' || character == '*' || character == '%' || character == '+' || character == '-')
        return true;
    else
        return false;
}

int getPrecedence(char character)
{
    if (character == '+' || character == '-')
        return 0;
    else if (character == '/' || character == '*' || character == '%')
        return 1;
    else if (character == '^')
        return 2;
}

int main()
{
    string infi = "a+b*c";
    char infix[9];
    for (int i = 0; i< infi.length(); i++){
        infix[i] = infi[i];
    }
    string postfix = "";
    int postfixTop = -1;
    string stack = "";
    int stackTop = -1;
    for (int i = 0; i < infi.length(); i++)
    {
        char infixChar = infix[i];
        if (isOperator(infix[i]) == false)
        {
            postfixTop++;
            postfix[postfixTop] = infix[i];
        }
        else
        {
            while (stackTop > -1  || stack[stackTop] != '('|| getPrecedence(infixChar) <= getPrecedence(stack[stackTop]))
            {
                if (stackTop <= -1 ) {
                    break;
                }
                postfix += stack[stackTop];
                postfixTop++;
                stackTop--;
            }
            stackTop++;
            stack.insert(stackTop, infix[i]);
        }
    }
    while (stackTop > -1)
    {
        postfix += stack[stackTop];
        stackTop--;
    }
    cout << postfix << "\n"
         << stack << endl;
    return 0;
}