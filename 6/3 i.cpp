#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

int sizeDoubly(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node *a = new Node{10}, *b = new Node{20}, *c = new Node{30};
    a->next = b; b->prev = a; b->next = c; c->prev = b;
    cout << "Size of Doubly Linked List: " << sizeDoubly(a);
}
