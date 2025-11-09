#include <iostream>
using namespace std;

struct Node {
    int coeff; // coefficient
    int pow;   // power
    Node* next;
};

// function to create a new node
Node* newNode(int c, int p) {
    Node* temp = new Node;
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;
    return temp;
}

// function to add two polynomial linked lists
Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 && poly2) {
        Node* temp = NULL;

        // if powers are same, add coefficients
        if (poly1->pow == poly2->pow) {
            temp = newNode(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            temp = newNode(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            temp = newNode(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }

        if (!result)
            result = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    // add remaining terms
    while (poly1) {
        tail->next = newNode(poly1->coeff, poly1->pow);
        poly1 = poly1->next;
        tail = tail->next;
    }
    while (poly2) {
        tail->next = newNode(poly2->coeff, poly2->pow);
        poly2 = poly2->next;
        tail = tail->next;
    }

    return result;
}

// function to print polynomial
void printPoly(Node* poly) {
    while (poly) {
        cout << "[" << poly->coeff << ", " << poly->pow << "]";
        if (poly->next) cout << " -> ";
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    // list1: 5x^2 + 4x^1 + 2x^0
    Node* poly1 = newNode(5, 2);
    poly1->next = newNode(4, 1);
    poly1->next->next = newNode(2, 0);

    // list2: 5x^1 + 5x^0
    Node* poly2 = newNode(5, 1);
    poly2->next = newNode(5, 0);

    Node* sum = addPolynomial(poly1, poly2);

    printPoly(sum);
    return 0;
}
