/***** HEADER FILES *****/
// <bits/stdc++.h> : STL facility store (vector, priority_queue, etc.)
#include <iostream>
using namespace std;

/*
Prim’s Algorithm:
- Maintain a priority_queue to always pick the smallest weight edge available
- Keep a visited array to avoid adding the same node twice → avoid cycle
*/

int main() {
    int n, m;
    cin >> n >> m;  // n = nodes, m = edges

    // Graph stored as adjacency list: graph[u] = { {v, weight}, ... }
    vector<pair<int,int>> graph[n + 1];

    // Input edges (assuming undirected)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // bidirectional
    }

    int start = 1; // We can start from ANY node → choosing 1 by swag 😎

    vector<int> visited(n + 1, 0); // Mark nodes already in MST
    int mstCost = 0; // Total weight of MST

    /*
    Min-Heap (priority_queue) storing: {weight, node}
    So smallest weight always on top 👑
    */
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Push the starting node with weight 0 (cost of including first node = 0)
    pq.push({0, start});

    cout << "Edges in MST:\n";

    // Run till all reachable nodes are included
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int weight = it.first; // cost of reaching 'node'
        int node = it.second;  // current node

        // If node already included → skip
        if (visited[node]) continue;

        // Include this node in MST
        visited[node] = 1;
        mstCost += weight;

        if (weight != 0) { 
            // weight == 0 only for the first node, so skip printing that
            cout << "Picked Node: " << node << " with weight: " << weight << "\n";
        }

        // Add neighbors of node into priority queue
        for (auto &p : graph[node]) {
            int adj = p.first;  // who’s next door
            int w = p.second;   // cost of going there
            if (!visited[adj]) {
                pq.push({w, adj}); // explore this later
            }
        }
    }

    cout << "Total MST Cost: " << mstCost << "\n";
}
