#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Display circular linked list (head repeated at end)
void display(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp->next != head) {  // traverse till last node
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << temp->data << " "; // print last node
    cout << head->data << endl; // repeat head
}

int main() {
    // Example circular linked list manually created
    Node n1 = {20, nullptr};
    Node n2 = {100, nullptr};
    Node n3 = {40, nullptr};
    Node n4 = {80, nullptr};
    Node n5 = {60, nullptr};

    // Linking nodes to form a circular list
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n1;  // circular link

    Node* head = &n1;
    display(head);

    return 0;
}
