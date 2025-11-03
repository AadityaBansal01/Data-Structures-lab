//Preorder: [A, B, D, E, C, F]
//Inorder:  [D, B, E, A, F, C]
//Left of A → [D, B, E]
//Right of A → [F, C]
//Now for left subtree:
//preorder (remaining) = [B, D, E, C, F]
//we only care about the part that matches [D, B, E] in inorder
//root of left subtree = B (next in preorder)
//Repeat recursively.
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

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end, int& preIndex, int n) {
    if (start > end || preIndex >= n)
        return NULL;

    // Pick current node from preorder
    Node* root = new Node(preorder[preIndex++]);

    // If no children (leaf node)
    if (start == end)
        return root;

    // Find the index of this node in inorder[]
    int pos = search(inorder, start, end, root->data);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex, n);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex, n);

    return root;
}

void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;
    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex, n);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    return 0;
}
