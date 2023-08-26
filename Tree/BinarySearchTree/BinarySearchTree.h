struct Node {
    int* data;
    Node* rightChild;
    Node* leftChild;
};

class BinarySearchTree {
    public:
    Node* root;
    BinarySearchTree();
    void insert(int data, Node* node);
    Node* search(int data, Node* node);
    // void delete(int data);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
};