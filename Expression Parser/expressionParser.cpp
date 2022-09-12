#include <iostream>
#include <cstring>

using namespace std;

bool isOperator(char character)
{
    if (character == '^' || character == '/' || character == '*' || character == '%' || character == '+' || character == '-' || character == '(' || character == ')' || character == ',')
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

char *infixToPostfix(char infix[])
{
    char *postfix = new char[(strlen(infix) + 1) * 2];
    int postfixTop = -1;
    char *stack = new char[strlen(infix) + 1];
    int stackTop = -1;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (isOperator(infix[i]) == false)
        {
            postfixTop++;
            postfix[postfixTop] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stackTop++;
            stack[stackTop] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[stackTop] != '(')
            {
                postfixTop++;
                postfix[postfixTop] = ',';
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
                if (stackTop <= -1)
                {
                    break;
                }
                if (stack[stackTop] == '(')
                {
                    break;
                }
                postfixTop++;
                postfix[postfixTop] = ',';
                postfixTop++;
                postfix[postfixTop] = stack[stackTop];
                stackTop--;
            }
            stackTop++;
            stack[stackTop] = infix[i];
            postfixTop++;
            postfix[postfixTop] = ',';
        }
    }
    while (stackTop > -1)
    {
        postfixTop++;
        postfix[postfixTop] = ',';
        postfixTop++;
        postfix[postfixTop] = stack[stackTop];
        stackTop--;
    }
    postfix[postfixTop+1] = '\0';
    return postfix;
}

float evaluatePostfix(char postfix[])
{
    char *numberString = new char[strlen(postfix)];
    int numberStringTop = -1;
    float *stack = new float[strlen(postfix)];
    int stackTop = -1;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isOperator(postfix[i]) == false)
        {
            numberStringTop++;
            numberString[numberStringTop] = postfix[i];
        }
        else if (postfix[i] == ',')
        {
            if (numberStringTop > -1)
            {
                stackTop++;
                stack[stackTop] = atoi(numberString);
                for (int k = 0; k <= numberStringTop; k++)
                {
                    numberString[k] = '\0';
                }
                numberStringTop = -1;
            }
        }
        else
        {

            float newStackItem;
            switch (postfix[i])
            {

            case '/':
                newStackItem = stack[stackTop - 1] / stack[stackTop];
                break;

            case '*':
                newStackItem = stack[stackTop - 1] * stack[stackTop];
                break;
            case '+':
                newStackItem = stack[stackTop - 1] + stack[stackTop];
                break;
            case '-':
                newStackItem = stack[stackTop - 1] - stack[stackTop];
                break;
            case '^':
                newStackItem = 1;
                for (int j = 0; j < stack[stackTop]; j++)
                {
                    newStackItem *= stack[stackTop - 1];
                }
                break;
            default:
                break;
            }
            stackTop--;
            stack[stackTop] = newStackItem;
        }
    }
    return stack[stackTop];
}

int main()
{
    char infix[] = "(3+9-10)*29^3/313";
    cout << "Infix to Postfix coversion:- " << infixToPostfix(infix) << endl;
    char *postfix = infixToPostfix(infix);
    cout << "Evaluation:- " << evaluatePostfix(postfix) << endl;

    return 0;
}
