#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    int data[] = {3,5,10,13,22,9,6};
    BinarySearchTree tree;
    for (const int item : data)
        tree.insert(item, tree.root);

    tree.inOrder(tree.root);
    cout << endl;
    tree.postOrder(tree.root);
    cout << endl;
    tree.preOrder(tree.root);
    return 0;
}