#include <iostream>
using namespace std;

// ---------------- PARITY FUNCTION ----------------
int parityCount(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

// ---------------- DOUBLY LINKED LIST ----------------
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

DNode* removeEvenParity(DNode* head) {
    DNode* curr = head;
    while (curr) {
        int parity = parityCount(curr->data);
        if (parity % 2 == 0) { // even parity
            DNode* del = curr;
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
        }
        curr = curr->next;
    }
    return head;
}

void printDLL(DNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <=> ";
        head = head->next;
    }
    cout << endl;
}

// ---------------- CIRCULAR LINKED LIST ----------------
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* removeEvenParity(Node* head) {
    if (!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;

    do {
        int parity = parityCount(curr->data);
        if (parity % 2 == 0) { // even parity
            if (curr == head) {
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                if (head->next == head) return NULL;
                temp->next = head->next;
                head = head->next;
                curr = head;
                continue;
            } else {
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;
}

void printCLL(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    cout << "Example 1: Circular Linked List\n";
    Node* head = new Node(9);
    head->next = new Node(11);
    head->next->next = new Node(34);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(21);
    head->next->next->next->next->next->next = head; // make circular

    cout << "Original CLL: 9 11 34 6 13 21\n";
    head = removeEvenParity(head);
    cout << "After removing even parity nodes: ";
    printCLL(head);

    cout << "\nExample 2: Doubly Linked List\n";
    DNode* head2 = new DNode(18);
    head2->next = new DNode(15);
    head2->next->prev = head2;
    head2->next->next = new DNode(8);
    head2->next->next->prev = head2->next;
    head2->next->next->next = new DNode(9);
    head2->next->next->next->prev = head2->next->next;
    head2->next->next->next->next = new DNode(14);
    head2->next->next->next->next->prev = head2->next->next->next;

    cout << "Original DLL: 18 <=> 15 <=> 8 <=> 9 <=> 14\n";
    head2 = removeEvenParity(head2);
    cout << "After removing even parity nodes: ";
    printDLL(head2);

    return 0;
}
