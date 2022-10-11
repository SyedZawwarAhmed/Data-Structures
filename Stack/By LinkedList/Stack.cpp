#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {

}

void Stack::push(int item) {
    Node *newNode = new Node();
    newNode->data = item;
    newNode->next = NULL;
    if (this->head == NULL) {
        this->head = newNode;
        this->top = this->head;
    }
    else {
        Node *temp = this->head;
        while (temp != NULL) {
            if (temp->next == NULL) {
                temp->next = newNode;
                temp->next->previous = temp;
                break;
            }
            temp = temp->next;
        }
        this->top = temp->next;
    }
}

int Stack::pop() {
    int result = this->top->data;
    this->top = this->top->previous;
    delete this->top->next;
    this->top->next = NULL;
    return result;
}

void Stack::print() {
    Node *temp = this->head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* Stack::getTop() {
    return this->top;
}