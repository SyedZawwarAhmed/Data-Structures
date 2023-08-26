class PriorityQueue {
    int *data;
    int size;
    int front = 1;
    int rear = 0;
    public:
    PriorityQueue(int size);
    int enqueue(int data);
    int dequeue();
    void print();
};