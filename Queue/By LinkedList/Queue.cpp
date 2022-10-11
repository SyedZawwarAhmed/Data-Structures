#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {

}

void Queue::enqueue(int item) {
    Node *newNode = new Node();
    newNode->data = item;
    newNode->next = NULL;
    if (this->front == NULL) {
        this->front = newNode;
        this->rear = this->front;
    }
    else {
        Node *temp = this->front;
        while (temp != NULL) {
            if (temp->next == NULL) {
                temp->next = newNode;
                temp->next->previous = temp;
                this->rear = temp->next;
                break;
            }
            temp = temp->next;
        }
    }
}

int Queue::dequeue() {
    if (this->front != NULL) {
        int result = this->front->data;
        Node* temp = this->front;
        this->front = temp->next;
        delete temp;
        temp = NULL;
        return result;
    }
    else {
        throw runtime_error{"Error: QueueUnderflow"};
    }
}

void Queue::print() {
    Node *temp = this->front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
