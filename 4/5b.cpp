#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // Move previous elements behind the new one 
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
int main() {
   

    cout << "\n--- Stack using One Queue ---\n";
    StackOneQueue s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    cout << "Top: " << s2.top() << endl; // 300
    s2.pop();
    cout << "Top after pop: " << s2.top() << endl; // 200

    return 0;
}