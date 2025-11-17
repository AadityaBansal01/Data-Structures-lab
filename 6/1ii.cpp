#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

// create new node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->prev = temp->next = NULL;
    return temp;
}

// insert at beginning
void insertFirst(int val) {
    Node* temp = newNode(val);
    if (!head) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// insert at end
void insertLast(int val) {
    Node* temp = newNode(val);
    if (!head) {
        head = temp;
        return;
    }
    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
}

// insert after a specific node
void insertAfter(int key, int val) {
    Node* curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        cout << "Node not found.\n";
        return;
    }

    Node* temp = newNode(val);
    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next)
        curr->next->prev = temp;
    curr->next = temp;
}

// insert before a specific node
void insertBefore(int key, int val) {
    Node* curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        cout << "Node not found.\n";
        return;
    }

    Node* temp = newNode(val);
    temp->next = curr;
    temp->prev = curr->prev;

    if (curr->prev)
        curr->prev->next = temp;
    else
        head = temp; // inserting before head

    curr->prev = temp;
}

// delete a specific node
void deleteNode(int key) {
    Node* curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        cout << "Node not found.\n";
        return;
    }

    if (curr->prev)
        curr->prev->next = curr->next;
    else
        head = curr->next; // deleting head

    if (curr->next)
        curr->next->prev = curr->prev;

    delete curr;
    cout << "Node " << key << " deleted.\n";
}

// search a node
void searchNode(int key) {
    Node* curr = head;
    while (curr) {
        if (curr->data == key) {
            cout << "Node found.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Node not found.\n";
}

// display list
void display() {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;

    while (true) {
        cout << "\n*** DOUBLY LINKED LIST MENU ***\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertFirst(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertLast(val);
                break;
            case 3:
                cout << "Enter key after which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertAfter(key, val);
                break;
            case 4:
                cout << "Enter key before which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                insertBefore(key, val);
                break;
            case 5:
                cout << "Enter node value to delete: ";
                cin >> key;
                deleteNode(key);
                break;
            case 6:
                cout << "Enter node value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 7:
                cout << "Linked List: ";
                display();
                break;
            case 8:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
