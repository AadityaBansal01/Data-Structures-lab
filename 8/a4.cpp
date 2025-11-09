#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// build tree from level order input (-1 means NULL)
Node* buildTree(vector<int> &arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// function to get right view
vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            // if it's the last node in the current level, add to right view
            if (i == n - 1) ans.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        Node* root = buildTree(arr);
        vector<int> view = rightView(root);

        for (int x : view) cout << x << " ";
        cout << endl;
    }
    return 0;
}
