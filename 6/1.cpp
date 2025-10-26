#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// ======== Display ========
void display() {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl; // last node
}

// ======== Insert at Beginning ========
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// ======== Insert at End ========
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// ======== Insert After Specific Node ========
void insertAfter(int key, int val) {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node* temp = head;
    while (temp->next != head && temp->data != key)
        temp = temp->next;

    if (temp->data != key) {
        cout << "Node " << key << " not found ❌\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// ======== Delete Specific Node ========
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node *curr = head, *prev = NULL;

    // Delete head node
    if (head->data == key) {
        if (head->next == head) { // single node
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        cout << "Deleted " << key << " ✅\n";
        return;
    }

    // Delete other nodes
    while (curr->next != head) {
        prev = curr;
        curr = curr->next;

        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted " << key << " ✅\n";
            return;
        }
    }

    cout << key << " not found ❌\n";
}

// ======== Search Node ========
void searchNode(int key) {
    if (head == NULL) {
        cout << "List empty!\n";
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        if (temp->data == key) {
            cout << "Found " << key << " ✅\n";
            return;
        }
        temp = temp->next;
    }

    if (temp->data == key)
        cout << "Found " << key << " ✅\n";
    else
        cout << key << " not found ❌\n";
}

// ======== Main Menu ========
int main() {
    int choice, val, key;

    while (true) {
        cout << "\n*** Circular Linked List Menu ***\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Node\n";
        cout << "4. Delete Node\n";
        cout << "5. Search Node\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter node value after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            insertAfter(key, val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteNode(key);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> key;
            searchNode(key);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
