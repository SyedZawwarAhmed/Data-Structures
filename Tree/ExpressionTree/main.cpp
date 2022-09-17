#include <iostream>
#include "ExpressionTree.h"

using namespace std;


int main()
{
    ExpressionTree expressionTree("abc*+d-");
    expressionTree.inOrder(expressionTree.root);
    cout << endl;
    expressionTree.postOrder(expressionTree.root);
    cout << endl;
    expressionTree.preOrder(expressionTree.root);
    return 0;
}