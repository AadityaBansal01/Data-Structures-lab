#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if a node is a leaf
bool isLeaf(Node* node) {
    return (node && !node->left && !node->right);
}

// Function to return the sum of all left leaves
int sumOfLeftLeaves(Node* root) {
    if (!root) return 0;

    int sum = 0;

    // If left child is a leaf, add its value
    if (isLeaf(root->left))
        sum += root->left->data;
    else
        sum += sumOfLeftLeaves(root->left);  // Recur for left subtree

    // Recur for right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    /* Constructing the tree:
             3
           /   \
          9    20
              /  \
             15   7
    */
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of left leaves: " << sumOfLeftLeaves(root) << endl;
    return 0;
}
