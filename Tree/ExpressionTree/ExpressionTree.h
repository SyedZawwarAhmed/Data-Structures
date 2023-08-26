struct Node
{
    char data;
    Node *rightChild;
    Node *leftChild;
};

class ExpressionTree
{

public:
    Node *root;
    ExpressionTree(char *postfix);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
};