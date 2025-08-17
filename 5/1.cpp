#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertAtBeginning(int val) {
    Node* n = new Node();
    n->data = val; n->next = head; head = n;
}
void insertAtEnd(int val) {
    Node* n = new Node(); n->data = val; n->next = NULL;
    if (!head) { head = n; return; }
    Node* t = head; while (t->next) t = t->next; t->next = n;
}
void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) { insertAtBeginning(val); return; }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (!t->next) return;
    Node* n = new Node(); n->data = val; n->next = t->next; t->next = n;
}
void insertAfter(int key, int val) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    Node* n = new Node(); n->data = val; n->next = t->next; t->next = n;
}
void deleteFromBeginning() {
    if (!head) return;
    Node* t = head; head = head->next; delete t;
}
void deleteFromEnd() {
    if (!head) return;
    if (!head->next) { delete head; head = NULL; return; }
    Node* t = head; while (t->next->next) t = t->next;
    delete t->next; t->next = NULL;
}
void deleteNode(int key) {
    if (!head) return;
    if (head->data == key) { deleteFromBeginning(); return; }
    Node* t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (!t->next) return;
    Node* d = t->next; t->next = t->next->next; delete d;
}
void search(int key) {
    Node* t = head; int pos = 1;
    while (t) { if (t->data == key) { cout << "Found at " << pos << endl; return; } t = t->next; pos++; }
    cout << "Not found\n";
}
void display() {
    Node* t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;
}

int main() {
    int ch,val,key;
    while (true) {
        cout<<"\n1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter\n";
        cout<<"5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Display 10.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: cin>>val; insertAtBeginning(val); break;
            case 2: cin>>val; insertAtEnd(val); break;
            case 3: cin>>key>>val; insertBefore(key,val); break;
            case 4: cin>>key>>val; insertAfter(key,val); break;
            case 5: deleteFromBeginning(); break;
            case 6: deleteFromEnd(); break;
            case 7: cin>>key; deleteNode(key); break;
            case 8: cin>>key; search(key); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}
