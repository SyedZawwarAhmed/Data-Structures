#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

class Queue
{
    Node *front = NULL;
    Node *rear = NULL;

public:
    Queue();
    void enqueue(int item);
    int dequeue();
    Node *getTop();
    void print();
};