#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to count and delete occurrences
int countAndDelete(Node*& head, int key) {
    int count = 0;

    // Delete occurrences at the start
    while (head && head->data == key) {
        count++;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            count++;
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1->2->1->2->1->3->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key = 1;
    cout << "Original List: ";
    printList(head);

    int cnt = countAndDelete(head, key);

    cout << "Count: " << cnt << endl;
    cout << "Updated List: ";
    printList(head);

    return 0;
}
