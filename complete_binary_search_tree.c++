#include<iostream>
#include<string>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Search in BST
bool searchInBst(node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    if (data < root->data) {
        return searchInBst(root->left, data);
    }
    else {
        return searchInBst(root->right, data);
    }
}

// Find minimum value node in BST
node* miniVal(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node in BST
node* deletenode(node* root, int data) {
    if (root == nullptr) return root;

    if (data < root->data)
        root->left = deletenode(root->left, data);
    else if (data > root->data)
        root->right = deletenode(root->right, data);
    else {
        // Case 1: No child (Leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            node* temp = miniVal(root->right); // Inorder Successor
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

// Insert a node in BST
node* insertIntoBst(node* root, int d) {
    if (root == NULL) {
        return new node(d);
    }
    if (d < root->data) {
        root->left = insertIntoBst(root->left, d);
    }
    else {
        root->right = insertIntoBst(root->right, d);
    }
    return root;
}

// Insert multiple data into BST
void insertData(node*& root) {
    int data;
    cout << "Enter numbers to insert (-1 to stop): ";
    cin >> data;

    while (data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Level Order Traversal (BFS)
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    insertData(root);

    cout << "Level Order Traversal of BST: " << endl;
    levelOrderTraversal(root);

    int key;
    cout << "\nEnter node to delete: ";
    cin >> key;

    root = deletenode(root, key);
   
    cout << "Level Order Traversal after deletion: " << endl;
    levelOrderTraversal(root);

    return 0;
}
