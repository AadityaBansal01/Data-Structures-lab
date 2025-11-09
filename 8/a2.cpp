#include <iostream>
using namespace std;

// --- Structure for each node ---
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🧠 Recursively generate all BSTs with values in range [start, end]
vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> allTrees;

    // ✅ Base Case 1: if range is invalid -> return {NULL}
    // This represents an *empty subtree* (important for leaf attachments)
    if (start > end) {
        allTrees.push_back(NULL);
        return allTrees;
    }

    // 🧩 Try every value in range [start, end] as the root
    for (int i = start; i <= end; i++) {

        // 🔹 Recursively get all possible left and right subtrees
        // left subtree uses all numbers smaller than i
        vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

        // right subtree uses all numbers greater than i
        vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

        // 🔗 Combine every possible left & right subtree with the current root i
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                allTrees.push_back(root);
            }
        }
    }

    return allTrees;
}

// 🌱 Wrapper function
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}

// --- Utility function to print tree in pre-order ---
void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// --- MAIN for testing ---
int main() {
    int n = 3;
    vector<TreeNode*> allBSTs = generateTrees(n);

    cout << "Total unique BSTs for n = " << n << " are: " << allBSTs.size() << endl;
    cout << "Preorder traversal of each BST:\n";

    for (int i = 0; i < allBSTs.size(); i++) {
        cout << i + 1 << ": ";
        preorder(allBSTs[i]);
        cout << endl;
    }
}
