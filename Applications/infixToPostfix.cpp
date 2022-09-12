#include <iostream>
#include <cstring>

using namespace std;

bool isOperator(char character)
{
    if (character == '^' || character == '/' || character == '*' || character == '%' || character == '+' || character == '-' || character == '(' || character == ')')
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

char* infixToPostfix(char infix[])
{
    char* postfix = new char[strlen(infix)];
    int postfixTop = -1;
    char* stack = new char[strlen(infix)];
    int stackTop = -1;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (isOperator(infix[i]) == false)
        {
            postfixTop++;
            postfix[postfixTop] = infix[i];
        }
        else if (infix[i] == '(') {
            stackTop++;
            stack[stackTop] = infix[i];
        }
        else if (infix[i] == ')') {
            while (stack[stackTop] != '(') {
                postfixTop++;
                postfix[postfixTop] = stack[stackTop];
                stackTop--;
            }
            stackTop--;
        }
        else
        {
            while (getPrecedence(infix[i]) <= getPrecedence(stack[stackTop]))
            {
                if (stackTop <= -1 ) {
                    break;
                }
                if (stack[stackTop] == '(') {
                    break;
                }
                postfixTop++;
                postfix[postfixTop] = stack[stackTop];
                stackTop--;
            }
            stackTop++;
            stack[stackTop] = infix[i];
        }
    }
    while (stackTop > -1)
    {
        postfixTop++;
        postfix[postfixTop] = stack[stackTop];
        stackTop--;
    }
    return postfix;
}

int main()
{
    char infix[] = "(a+b)*(c-d)";
    cout << infixToPostfix(infix) << endl;
    return 0;
}
