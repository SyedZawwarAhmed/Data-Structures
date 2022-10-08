#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size)
{
    this->size = size;
    this->data = new int[size];
}

void Stack::push(int item)
{
    this->top++;
    if (this->top >= this->size)
        throw runtime_error {"Error: StackOverflow"};
    else
        this->data[top] = item;
}

int Stack::pop()
{
    this->top--;
    if (this->top < -1) 
    throw runtime_error {"Error: StackUnderflow"};
    else
    return this->data[top];
}

int Stack::getTop() {
    return this->top;
}

void Stack::print()
{
    for (int i = 0; i <= this->top; i++)
    {
        cout << this->data[i] << endl;
    }
}