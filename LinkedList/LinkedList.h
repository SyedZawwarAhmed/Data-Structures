#include <iostream>

using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head = NULL;

public:
    void append(int data);
    void print();
};