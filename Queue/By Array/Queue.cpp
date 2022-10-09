#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int size)
{
    this->size = size;
    this->data = new int[size];
}

void Queue::enqueue(int item)
{
    this->rear++;
    if (this->rear >= size)
        throw runtime_error{"Error: QueueOverflow"};
    else
    {
        this->data[rear] = item;
    }
}

void Queue::dequeue()
{
    if (this->front > this->rear)
        throw runtime_error{"Error: QueueUnderflow"};
    else {
        for (int i = this->front+1; i<this->rear; i++) {
            this->data[i-1]=this->data[i];
        }
        this->rear--;
    }
}

void Queue::print()
{
    for (int i = this->front; i <= this->rear; i++)
    {
        cout << data[i] << endl;
    }
}
