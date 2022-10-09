#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack() {

}

void Stack::push(int item) {
    if (this->head == NULL) {
        this->head = new Node();
        this->head->data = item;
        this->head->next = NULL;
        this->top = this->head;
    }
    else {
        Node *temp = this->head;
        while (temp != NULL) {
            if (temp->next == NULL) {
                temp->next = new Node();
                temp->next->data = item;
                temp->next->next = NULL;
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