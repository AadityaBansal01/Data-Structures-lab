#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int x) : data(x), right(NULL), left(NULL), up(NULL), down(NULL) {}
};

// ---------- CONVERT 2D MATRIX TO DOUBLY LINKED GRID ----------
Node* constructDLLFromMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    if (n == 0) return NULL;
    int m = mat[0].size();

    // store nodes in 2D vector for linking
    vector<vector<Node*>> nodes(n, vector<Node*>(m, NULL));

    // create all nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // link nodes with their neighbors
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < m - 1) nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < n - 1) nodes[i][j]->down = nodes[i + 1][j];
        }
    }

    return nodes[0][0]; // top-left node (head)
}

// ---------- PRINT BY ROWS ----------
void printGrid(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* col = row;
        for (int j = 0; j < m; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

// ---------- MAIN ----------
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = constructDLLFromMatrix(mat);

    cout << "Doubly Linked List (4-directional) representation:\n";
    printGrid(head, 3, 3);

    return 0;
}
