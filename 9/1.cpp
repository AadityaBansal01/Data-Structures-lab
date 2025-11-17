#include <iostream>
#include <queue>   // queue is needed for BFS
using namespace std;

int main() {
    // -------------------- BASIC CONCEPT --------------------
    // BFS (Breadth First Search) is a graph traversal algorithm.
    // It visits all the vertices of a graph in a "level by level" manner.
    // It starts from a given source vertex and explores all its neighbors first,
    // then moves to the next level of neighbors.
    //
    // It uses a "queue" data structure to keep track of the next node to visit.
    // BFS works for both adjacency matrix and adjacency list representations.
    // --------------------------------------------------------

    const int MAX = 100;  // maximum possible vertices
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Step 1: Take adjacency matrix input
    // adj[i][j] = 1 means there is an edge from vertex i to vertex j
    int adj[MAX][MAX];
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Step 2: Choose a starting vertex for BFS
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // Step 3: Create a visited array to keep track of visited nodes
    int visited[MAX] = {0};

    // Step 4: Create a queue to store nodes to be visited
    queue<int> q;

    // Step 5: Mark the starting node as visited and enqueue it
    visited[start] = 1;
    q.push(start);

    cout << "\nBFS Traversal: ";

    // Step 6: Process the queue until it becomes empty
    while (!q.empty()) {
        // Remove the front element from the queue
        int node = q.front();
        q.pop();

        // Print (or process) the current node
        cout << node << " ";

        // Step 7: Visit all the adjacent (connected) vertices of the current node
        for (int i = 0; i < n; i++) {
            // If an edge exists and the vertex is not visited yet
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;  // mark it as visited
                q.push(i);       // add it to the queue for future visit
            }
        }
    }

    return 0;
}
