#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(int size) {
    this->size = size + 1;
    this->data = new int[size + 1];
}

int PriorityQueue::enqueue(int data) {
    this->data[++rear] = data;
    int i = rear;
    while (i > 1) {
        if (this->data[i] < this->data[i/2]) {
            int temp = this->data[i];
            this->data[i] = this->data[i/2];
            this->data[i/2] = temp;
            i = i/2;
        }
        else break;
    }
    return data;
}

int PriorityQueue::dequeue() {
    return data[this->front++];
}

void PriorityQueue::print() {
    for (int i=front; i<=rear; i++) {
        cout << this->data[i];
    }
    cout << endl;
}