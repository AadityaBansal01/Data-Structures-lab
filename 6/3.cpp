#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getCircularListSize(Node* head) {
    if (head == NULL) return 0;

    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Creating a circular linked list: 10 -> 20 -> 30 -> 10
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head->next = second;
    second->next = third;
    third->next = head; // circular connection

    cout << "Size of Circular Linked List = " << getCircularListSize(head) << endl;
    return 0;
}
