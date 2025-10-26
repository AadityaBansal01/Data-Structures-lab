#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to split circular linked list
void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == NULL) return;

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even nodes, move fast one more step
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of two halves
    *head1_ref = head;
    *head2_ref = slow->next;

    // Make first half circular
    fast->next = slow->next;
    // Make second half circular
    slow->next = head;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Create circular linked list: 10 -> 4 -> 9 -> back to 10
    Node* head = new Node{10, NULL};
    Node* second = new Node{4, NULL};
    Node* third = new Node{9, NULL};

    head->next = second;
    second->next = third;
    third->next = head;

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircularList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}
