#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse K nodes of linked list
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    // Step 1: Check if there are at least k nodes ahead
    int count = 0;
    Node* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) {
        // Not enough nodes to reverse → return as is
        return head;
    }

    // Step 2: Reverse first k nodes
    count = 0;
    curr = head;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recurse for remaining list and connect
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // Step 4: prev is the new head of this reversed group
    return prev;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "→";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1: Linked list = 1→2→3→4→5→6→7→8→9, K=3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    int K = 3;
    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, K);

    cout << "Reversed in groups of " << K << ": ";
    printList(head);

    return 0;
}
