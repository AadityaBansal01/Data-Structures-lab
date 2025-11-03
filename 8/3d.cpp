#include <iostream>
#include <queue>   // for level-order traversal (BFS)
using namespace std;

// Structure for a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to find the minimum depth of BST
int minDepth(Node* root) {
    if (!root) return 0;  // empty tree → depth = 0

    queue<pair<Node*, int>> q;  // store node + its current depth
    q.push({root, 1});          // start from root at depth 1

    while (!q.empty()) {
        auto [node, depth] = q.front(); // get front node and its depth
        q.pop();

        // If this node is a leaf (no children), we've found the min depth
        if (!node->left && !node->right)
            return depth;

        // Push children into queue with depth +1
        if (node->left)
            q.push({node->left, depth + 1});
        if (node->right)
            q.push({node->right, depth + 1});
    }

    return 0; // (unreachable technically)
}

int main() {
    // Example BST:
    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5

    Node* root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->left = new Node{4};
    root->left->right = new Node{5};

    cout << "Minimum Depth of BST: " << minDepth(root);
}
//We do a level-order traversal (BFS).
//As soon as we hit a leaf node (no left/right child), that level’s depth is the minimum depth.
//BFS ensures the first leaf we encounter is the shallowest one.
