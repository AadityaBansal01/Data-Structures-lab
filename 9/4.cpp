/***** HEADER FILES *****/
// <bits/stdc++.h> gives us: vector, priority_queue, pair, etc.
#include <iostream>
using namespace std;

/*
Dijkstra Concept:
We keep a distance array → stores cheapest cost to reach each node
Priority Queue (Min-Heap) → always picks the least cost node next
Graph represented as adjacency list: graph[u] = {{v, weight}, ...}
*/

int main() {
    int n, m;
    cin >> n >> m; // n = nodes, m = edges

    // Adjacency list: for each node store -> (neighbor, weight)
    vector<pair<int,int>> graph[n + 1];

    // Reading edges (assuming undirected, if directed → remove second push)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // edge u -> v with cost w
        graph[v].push_back({u, w}); // u <-> v (bidirectional graph)
    }

    int src;
    cin >> src; // the node we start from

    // Distance array — initialize everyone to VERY large number (infinity)
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0; // source → cost 0 (we are already here)

    /*
    Priority queue (min-heap):
    Stores pairs like {cost to reach node, node ID}
    So top() always gives us the next cheapest node to explore
    */
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, src}); // start from source node

    // Dijkstra magic starts
    while (!pq.empty()) {
        int cost = pq.top().first; // current shortest distance known
        int u = pq.top().second;   // current node
        pq.pop();

        // If we already found a cheaper path, skip this outdated one
        if (cost > dist[u]) continue;

        // Explore neighbors of u
        for (auto &it : graph[u]) {
            int v = it.first;   // neighbor
            int w = it.second;  // weight of edge u -> v

            // If found a cheaper path → update & push to queue
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Final Output
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> Cost: " << dist[i] << "\n";
    }
}
