/***** HEADER FILES *****/
// <bits/stdc++.h> : One-stop shop for all common STL stuff (vectors, sorting, etc.)
#include <iostream>
using namespace std;

/***** Disjoint Set Union (DSU) aka Union-Find *****/
// Purpose: Keep track of which nodes belong to the same group (so no cycles)

/*
findParent():
- Takes a node and returns the leader (root parent) of its set
- Path Compression: Makes future searches faster by directly linking to the leader
*/
int findParent(int node, vector<int>& parent) {
    // Base case: If node is its own parent, it's the boss
    if (parent[node] == node) 
        return node;

    // Recursive: Go find the real boss & make this node directly follow boss for speed
    return parent[node] = findParent(parent[node], parent);
}

/*
unionSet():
- Joins two groups if they are different
- Uses rank to keep tree shallow → faster
*/
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent); // find boss of u
    v = findParent(v, parent); // find boss of v

    // If they are different groups → merge them
    if (u != v) {
        // Attach smaller rank tree under larger rank tree
        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++; // increase rank if both same height
        }
    }
}

/***** MAIN FUNCTION *****/
int main() {
    int n, m;
    cin >> n >> m;  // n = number of nodes | m = number of edges

    /*
    edges vector:
    We store edges as {weight, node1, node2}
    Why weight first? So sorting automatically sorts by weight
    */
    vector<vector<int>> edges;

    // Taking input of all edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // nodes & weight
        edges.push_back({w, u, v}); // push in sorted-friendly order
    }

    // Sorting edges based on weight (ascending)
    sort(edges.begin(), edges.end());

    // DSU setup
    vector<int> parent(n + 1); // parent[i] tells who’s the boss of node i
    vector<int> rank(n + 1, 0); // rank keeps height approx.

    // Initially every node is its own parent (everyone is their own boss 😎)
    for (int i = 1; i <= n; i++) 
        parent[i] = i;

    int mstCost = 0; // total cost of MST
    vector<pair<int,int>> mstEdges; // store edges actually used

    /***** MAIN KRUSKAL LOGIC STARTS *****/
    /*
    Loop through sorted edges
    Always try to pick the cheapest edge first:
    If picking the edge does NOT create a cycle → accept it
    Else ignore it like your toxic ex 😌
    */
    for (auto &e : edges) {
        int w = e[0]; 
        int u = e[1];
        int v = e[2];

        // Check if adding this edge forms a cycle
        if (findParent(u, parent) != findParent(v, parent)) { 
            mstCost += w; // add weight to answer
            mstEdges.push_back({u, v}); // mark this edge as chosen
            unionSet(u, v, parent, rank); // merge their sets
        }
    }

    /***** OUTPUT *****/
    cout << "Total MST Cost: " << mstCost << "\n";
    cout << "Edges in MST:\n";
    for (auto &p : mstEdges) {
        cout << p.first << " - " << p.second << "\n"; // edges selected
    }
}
