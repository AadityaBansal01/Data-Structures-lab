#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to check BST using min-max approach
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data < minVal || root->data > maxVal)
        return false;

    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}

// Utility function to insert node in BST (for testing)
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);  // builds BST
    }

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "The tree is a BST ✅\n";
    else
        cout << "The tree is NOT a BST ❌\n";

    return 0;
}
