#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if list is circular
bool isCircular(Node* head) {
    if (!head) return false; // empty list not circular

    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    // Example 1: circular list
    Node n1 = {10, nullptr};
    Node n2 = {20, nullptr};
    Node n3 = {30, nullptr};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1; // circular

    Node* head1 = &n1;
    cout << "List 1 is circular? " << (isCircular(head1) ? "Yes" : "No") << endl;

    // Example 2: non-circular list
    Node m1 = {1, nullptr};
    Node m2 = {2, nullptr};
    Node m3 = {3, nullptr};

    m1.next = &m2;
    m2.next = &m3;
    m3.next = nullptr; // not circular

    Node* head2 = &m1;
    cout << "List 2 is circular? " << (isCircular(head2) ? "Yes" : "No") << endl;

    return 0;
}
