#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    this->root = new Node();
    this->root->data = NULL;
    this->root->rightChild = NULL;
    this->root->leftChild = NULL;
}

void BinarySearchTree::insert(int data, Node *node)
{
    if (node->data == NULL)
    {
        node->data = new int(data);
        node->rightChild = new Node();
        node->leftChild = new Node();
    }
    else
    {
        if (data > *node->data)
        {
            insert(data, node->rightChild);
        }
        else if (data <= *node->data)
        {
            insert(data, node->leftChild);
        }
    }
}

void BinarySearchTree::inOrder(Node *node)
{
    if (node->leftChild != NULL)
        inOrder(node->leftChild);

    if (node->data != NULL)
    cout << *node->data << " ";

    if (node->rightChild != NULL)
        inOrder(node->rightChild);
}


void BinarySearchTree::postOrder (Node* node) {
    if (node->leftChild != NULL)
    postOrder(node->leftChild);

    if (node->rightChild != NULL)
    postOrder(node->rightChild);

    if (node->data != NULL)
    cout << *node->data << " ";
}

void BinarySearchTree::preOrder (Node* node) {
    if (node->data != NULL)
    cout << *node->data << " ";

    if (node->leftChild != NULL)
    preOrder(node->leftChild);

    if (node->rightChild != NULL)
    preOrder(node->rightChild);
}
