#include <iostream>
using namespace std;

// DFS function to visit all nodes connected to 'node'
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1; // mark current node as visited

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited); // go deeper
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // adjacency list
    vector<vector<int>> adj(V);

    // reading edges (u v)
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // because graph is undirected
    }

    vector<int> visited(V, 0);
    int connectedComponents = 0;

    // check every node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            connectedComponents++;  
            dfs(i, adj, visited); // explore the whole component
        }
    }

    cout << connectedComponents;
    return 0;
}
