#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

class Stack
{
    Node *head = NULL;
    Node *top = NULL;

public:
    Stack();
    void push(int item);
    int pop();
    Node *getTop();
    void print();
};