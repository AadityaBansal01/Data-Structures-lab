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
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void display(Node* h) {
    while (h) { cout << h->data << "->"; h = h->next; }
    cout << "NULL\n";
}

int findMiddle(Node* h) {
    Node* slow = h;
    Node* fast = h;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    cout << "List: ";
    display(head);

    cout << "Middle element: " << findMiddle(head) << endl;
}
