//inorder predecessor of a node is the maximum node in the left subtree
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// ---------- FUNCTION TO FIND INORDER PREDECESSOR ----------
Node* inorderPredecessor(Node* root, Node* x) {
    if (!root || !x) return NULL;

    // Case 1: If left subtree exists → find max in left subtree
    if (x->left) {
        Node* temp = x->left;
        while (temp->right)
            temp = temp->right;
        return temp;
    }

    // Case 2: No left subtree → go up to first ancestor where node is in right subtree
    Node* predecessor = NULL;
    Node* ancestor = root;

    while (ancestor != x) {
        if (x->data > ancestor->data) {
            predecessor = ancestor;  // potential predecessor
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}

// ---------- HELPER TO INSERT INTO BST ----------
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ---------- MAIN ----------
int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    Node* x = root->left->right->right; // Node with value 14

    Node* pred = inorderPredecessor(root, x);
    if (pred)
        cout << "Inorder Predecessor of " << x->data << " is " << pred->data << endl;
    else
        cout << "No Inorder Predecessor exists for " << x->data << endl;

    return 0;
}
