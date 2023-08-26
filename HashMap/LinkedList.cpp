#include <iostream>
#include "LinkedList.h"

using namespace std;

void LinkedList::append(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (this->head == NULL)
    {
        head = newNode;
    }
    else
    {

        Node *tempNext = head;
        while (true)
        {
            if (tempNext != NULL)
            {
                if (tempNext->next == NULL)
                {
                    tempNext->next = newNode;
                    break;
                }
                tempNext = tempNext->next;
            }
        }
    }
}

bool LinkedList::find(int item) {
    Node *tempNext;
    tempNext = head;
    while (tempNext != NULL)
    {
        if (tempNext->data == item) {
            return true;
        }
        tempNext = tempNext->next;
    }
    return false;
}

void LinkedList::print()
{
    Node *tempNext;
    tempNext = head;
    while (tempNext != NULL)
    {
        cout << tempNext->data << endl;
        tempNext = tempNext->next;
    }
}