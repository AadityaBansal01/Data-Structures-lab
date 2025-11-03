//In postorder, the last element is always the root.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Find position of element in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree from inorder and postorder
Node* buildTree(int inorder[], int postorder[], int start, int end, int& postIndex, int n) {
    if (start > end || postIndex < 0)
        return NULL;

    // Pick current node from postorder
    Node* root = new Node(postorder[postIndex--]);

    // If it's a leaf node
    if (start == end)
        return root;

    // Find root position in inorder
    int pos = search(inorder, start, end, root->data);

    // Build right first (since postorder goes Left → Right → Root)
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex, n);
    root->left = buildTree(inorder, postorder, start, pos - 1, postIndex, n);

    return root;
}

// Inorder print to verify
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;
    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    int postIndex = n - 1; // start from end
    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex, n);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    return 0;
}
