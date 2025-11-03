#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Utility: get length of list
int getLength(ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;

    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Find difference
    int diff = abs(lenA - lenB);

    // Move longer list's pointer ahead
    if (lenA > lenB) {
        while (diff--) headA = headA->next;
    } else {
        while (diff--) headB = headB->next;
    }

    // Now move together until they meet
    while (headA && headB) {
        if (headA == headB) return headA; // intersection found
        headA = headA->next;
        headB = headB->next;
    }

    return NULL; // no intersection
}

int main() {
    // Example: creating intersection manually
    ListNode* common = new ListNode(8);
    common->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection) 
        cout << "Intersected at " << intersection->val << endl;
    else 
        cout << "No intersection" << endl;

    return 0;
}
//diff = abs(lenA - lenB) → diff = 1