#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int val) {   // helper to create list
    Node* n = new Node();
    n->data = val; n->next = NULL;
    if (!head) { head = n; return; }
    Node* t = head; while (t->next) t = t->next; t->next = n;
}

void display(Node* h) {
    while (h) { cout << h->data << "->"; h = h->next; }
    cout << "NULL\n";
}

Node* reverse(Node* h) {
    Node* prev = NULL, *curr = h, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);

    cout << "Original: ";
    display(head);

    head = reverse(head);

    cout << "Reversed: ";
    display(head);
}
