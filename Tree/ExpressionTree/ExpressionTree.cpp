#include <iostream>
#include <cstring>
#include "ExpressionTree.h"

using namespace std;

bool isOperator(char character)
{
    return character == '^' || character == '/' || character == '*' || character == '%' || character == '+' || character == '-' || character == '(' || character == ')' || character == ',';
}

ExpressionTree::ExpressionTree(char* postfix) {
    Node** stack = new Node*[strlen(postfix)];
    int stackTop = -1;
    for (int i=0; i<strlen(postfix); i++) {
        if (!isOperator(postfix[i])) {
            Node* newNode = new Node;
            newNode->data = postfix[i];
            newNode->rightChild = newNode->leftChild = NULL;
            stack[++stackTop] = newNode;
        }
        else {
            Node* newNode = new Node;
            newNode->data = postfix[i];
            newNode->rightChild = stack[stackTop--];
            newNode->leftChild = stack[stackTop--];
            stack[++stackTop] = newNode;
        }
    }
    this->root = stack[stackTop--];
}

void ExpressionTree::inOrder (Node* node) {
    if (node->leftChild != NULL)
    inOrder(node->leftChild);

    cout << node->data;

    if (node->rightChild != NULL)
    inOrder(node->rightChild);
}

void ExpressionTree::postOrder (Node* node) {
    if (node->leftChild != NULL)
    postOrder(node->leftChild);

    if (node->rightChild != NULL)
    postOrder(node->rightChild);

    cout << node->data;
}

void ExpressionTree::preOrder (Node* node) {
    cout << node->data;

    if (node->leftChild != NULL)
    preOrder(node->leftChild);

    if (node->rightChild != NULL)
    preOrder(node->rightChild);
}
