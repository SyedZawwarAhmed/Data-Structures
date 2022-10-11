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
    int result = this->front->data;
    Node* temp = this->front;
    this->front = NULL;
    this->front = temp->next;
    this->front->previous = NULL;
    delete temp;
    temp = NULL;
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
