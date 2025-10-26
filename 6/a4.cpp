#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *random;
    Node(int x) : data(x), next(NULL), prev(NULL), random(NULL) {}
};

// -------- FIX RANDOM POINTER --------
void correctRandomPointer(Node* head) {
    if (!head) return;

    Node* curr = head;
    while (curr) {
        // expected random pointer = prev node
        if (curr->random != curr->prev) {
            curr->random = curr->prev;
        }
        curr = curr->next;
    }
}

// -------- PRINT FUNCTION --------
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node: " << curr->data << ", ";
        if (curr->random)
            cout << "Random -> " << curr->random->data << endl;
        else
            cout << "Random -> NULL\n";
        curr = curr->next;
    }
}

// -------- MAIN FUNCTION --------
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    // correct randoms except one messed up
    head->random = NULL;
    head->next->random = head;           // correct
    head->next->next->random = head;     // WRONG (should be head->next)

    cout << "Before correction:\n";
    printList(head);

    correctRandomPointer(head);

    cout << "\nAfter correction:\n";
    printList(head);

    return 0;
}
