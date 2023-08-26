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
    bool find (int item);
    void print();
};