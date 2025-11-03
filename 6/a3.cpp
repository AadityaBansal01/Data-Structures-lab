#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// ----------- REVERSE FUNCTION ------------
Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* newHead = NULL;
    Node* groupPrev = NULL;

    while (curr) {
        Node* groupStart = curr;
        Node* prev = NULL;
        int count = 0;

        // reverse k nodes
        while (curr && count < k) {
            Node* nxt = curr->next;
            curr->next = prev;
            curr->prev = nxt;
            prev = curr;
            curr = nxt;
            count++;
        }

        // connect previous group
        if (!newHead) newHead = prev;
        if (groupPrev) {
            groupPrev->next = prev;
            prev->prev = groupPrev;
        }

        groupPrev = groupStart;
    }
    return newHead;
}

// ----------- PRINT FUNCTION ------------
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL\n";
}

// ----------- MAIN FUNCTION ------------
int main() {
    // Example 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original DLL: ";
    printList(head);

    int k = 2;
    head = reverseInGroups(head, k);
    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    // Example 2
    Node* head2 = new Node(1);
    Node* temp = head2;
    for (int i = 2; i <= 6; i++) {
        temp->next = new Node(i);
        temp->next->prev = temp;
        temp = temp->next;
    }

    cout << "\nOriginal DLL: ";
    printList(head2);
    k = 4;
    head2 = reverseInGroups(head2, k);
    cout << "Reversed in groups of " << k << ": ";
    printList(head2);

    return 0;
}
//If list is empty or group size ≤ 1 → no need to reverse.
//NULL <- 1 <-> 2 -> 3
//Iteration 1
//curr = 1
//nxt = 2
//Change 1->next to NULL (because prev is NULL initially)
//Change 1->prev to point to 2 (since we flipped direction)
//Move forward:
//prev = 1, curr = 2
