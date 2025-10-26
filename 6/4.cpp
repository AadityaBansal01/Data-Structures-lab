#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Function to check if DLL is palindrome
bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* tail = head;
    while (tail->next) tail = tail->next; // move to last node

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    // Creating DLL: R -> A -> D -> A -> R
    Node* n1 = new Node{'R', NULL, NULL};
    Node* n2 = new Node{'A', NULL, n1};
    Node* n3 = new Node{'D', NULL, n2};
    Node* n4 = new Node{'A', NULL, n3};
    Node* n5 = new Node{'R', NULL, n4};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << (isPalindrome(n1) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
