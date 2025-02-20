#include <iostream>
using namespace std;

// AVL Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

// Function to get height of a node
int getHeight(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to get balance factor
int getBalanceFactor(Node* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right Rotate (LL Rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;  // New root
}

// Left Rotate (RR Rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;  // New root
}

// Insert into AVL Tree and balance it
Node* insert(Node* root, int data) {
    if (root == NULL) return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;  // No duplicate values in AVL tree

    // Update height of current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get Balance Factor
    int balance = getBalanceFactor(root);

    // **Balance the Tree**
    // Case 1: Left Heavy (LL Rotation)
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    // Case 2: Right Heavy (RR Rotation)
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    // Case 3: Left-Right Heavy (LR Rotation)
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right-Left Heavy (RL Rotation)
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal to print the AVL tree
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Inserting nodes into AVL Tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 2); // This will trigger LL Rotation

    cout << "Inorder Traversal of Balanced AVL Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
