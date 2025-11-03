//inorder successor of a node is the minimum node in the right subtree 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// ---------- FUNCTION TO FIND INORDER SUCCESSOR ----------
Node* inorderSuccessor(Node* root, Node* x) {
    if (!root || !x) return NULL;

    // Case 1: If right subtree exists → smallest in right subtree
    if (x->right) {
        Node* temp = x->right;
        while (temp->left)
            temp = temp->left;
        return temp;
    }

    // Case 2: No right subtree → find ancestor
    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != x) {
        if (x->data < ancestor->data) {
            successor = ancestor;   // potential successor
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
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

    Node* succ = inorderSuccessor(root, x);
    if (succ)
        cout << "Inorder Successor of " << x->data << " is " << succ->data << endl;
    else
        cout << "No Inorder Successor exists for " << x->data << endl;

    return 0;
}
