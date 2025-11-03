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

// Rotate left by k positions
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: find length and last node
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    // Step 2: normalize k
    k = k % len;
    if (k == 0) return head;

    // Step 3: make list circular
    temp->next = head;  // last node points to head

    // Step 4: move to kth node (new tail)
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // Step 5: node after newTail is new head
    Node* newHead = newTail->next;

    // Step 6: break the circle
    newTail->next = NULL;

    return newHead;
}

// Utility: print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Build list: 1->2->3->4->5->6->7
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    int k = 4;

    cout << "Original List: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
//Find the length and last node
//Handle extra rotations
//Make the list circular
//Move to the kth node (new tail)
//The node after that (5) is new head
//Break the circle