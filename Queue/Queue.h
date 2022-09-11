class Queue
{
    int front = 0;
    int rear = -1;
    int size;
    int *data;

public:
    Queue(int size);
    void enqueue(int item);
    void dequeue();
    void print();
};