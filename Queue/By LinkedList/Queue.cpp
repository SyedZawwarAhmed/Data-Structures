#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {

}

void Queue::enqueue(int item) {
    if (this->front == NULL) {
        this->front = new Node();
        this->front->data = item;
        this->front->next = NULL;
        this->rear = this->front;
    }
    else {
        Node *temp = this->front;
        while (temp != NULL) {
            if (temp->next == NULL) {
                temp->next = new Node();
                temp->next->data = item;
                temp->next->next = NULL;
                temp->next->previous = temp;
                this->rear = temp->next;
                break;
            }
            temp = temp->next;
        }
    }
}

int Queue::dequeue() {
    int result = this->front->data;
    Node* temp = new Node();
    temp->data = this->front->next->data;
    temp->next = this->front->next->next;
    delete this->front;
    this->front = new Node;
    this->front->data = temp->data;
    this->front->next = temp->next;
    delete temp;
    return result;
}

void Queue::print() {
    Node *temp = this->front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
