#include <iostream>

using namespace std;

class Stack
{
    int top = -1;
    int size;
    int *data;

public:
    Stack(int size);
    void push(int item);
    int pop();
    int getTop();
    void print();
};