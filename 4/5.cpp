#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        /* Always push into empty q2 	push(x) → always push into the empty queue, then move all elements from the other queue into it.
	•	pop() → just pop from the front of the non-empty queue.*/
        q2.push(x);

        // Move all elements of q1 into q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap names of q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
int main() {
    cout << "--- Stack using Two Queues ---\n";
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl; // 30
    s1.pop();
    cout << "Top after pop: " << s1.top() << endl; // 20

    cout << "\n--- Stack using One Queue ---\n";

    return 0;
}