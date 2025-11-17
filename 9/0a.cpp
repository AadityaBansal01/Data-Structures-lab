#include <iostream>
using namespace std;

// structure for linked list node
struct Node {
    int data;      // stores vertex number connected to current vertex
    Node* next;    // pointer to next node in adjacency list
};

// class to represent a graph
class Graph {
    int V;         // number of vertices
    Node** adj;    // array of linked lists (adjacency list)
public:
    // constructor to initialize graph
    Graph(int v) {
        V = v;                         // store number of vertices
        adj = new Node*[V];            // create array of linked list heads
        for (int i = 0; i < V; i++)
            adj[i] = NULL;             // initially, all lists are empty
    }

    // function to add an undirected edge (insertion at front)
    void addEdge(int src, int dest) {
        // -------- insert at front of src's list --------
        Node* newNode = new Node;      // create new node
        newNode->data = dest;          // store destination vertex
        newNode->next = adj[src];      // link new node to current head
        adj[src] = newNode;            // make new node the new head (insert at front)

        // -------- insert at front of dest's list --------
        // because undirected graph -> both directions
        newNode = new Node;            // create another node
        newNode->data = src;           // store source vertex
        newNode->next = adj[dest];     // link to current head
        adj[dest] = newNode;           // make new node the new head (insert at front)
    }

    // function to display the adjacency list
    void display() {
        cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";

            Node* temp = adj[i];       // pointer to traverse linked list
            while (temp != NULL) {
                cout << temp->data << " ";   // print connected vertex
                temp = temp->next;           // move to next node
            }
            cout << endl;                    // new line for next vertex
        }
    }
};

// main function
int main() {
    int V, E;       // number of vertices and edges

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);     // create graph object

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter each edge as: source destination\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;    // input edge
        g.addEdge(src, dest);  // add edge using front insertion
    }

    // display adjacency list
    g.display();

    return 0;
}
