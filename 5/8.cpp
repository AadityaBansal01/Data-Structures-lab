#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd’s cycle-finding algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  // Loop found
            break;
        }
    }

    // No loop
    if (slow != fast) return;

    // Step 2: Find start of the loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    // Now 'slow' (or 'fast') is at the start of loop

    // Step 3: Find last node in loop and break it
    Node* ptr = slow;
    while (ptr->next != slow) {
        ptr = ptr->next;
    }
    ptr->next = NULL;  // Break loop
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list with loop: 1->2->3->4->5->6->3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Creating loop manually
    head->next->next->next->next->next->next = head->next->next; // 6->3

    removeLoop(head);

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}