// DFS on a graph using adjacency list.
// This version is the cleanest and EXACT standard for MAANG.

// We use:
// visited[]  -> to avoid revisiting nodes
// dfs()      -> go deep, then return back
// graph      -> adjacency list

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    // mark this node visited
    visited[node] = true;

    cout << node << " ";   // process this node

    // explore all neighbors
    for (int neighbor : graph[node]) {

        // only go if not visited
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);  // go deeper
        }
    }
}

int main() {
    int n = 5;  // total nodes: 0..4

    vector<vector<int>> graph(n);

    // making an undirected graph:
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    vector<bool> visited(n, false);

    cout << "DFS starting from node 0:\n";
    dfs(0, graph, visited);

    return 0;
}
