#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> st;      // normal stack
    stack<int> minSt;   // stack to track minimums

public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }

    void pop() {
        if (st.empty()) return;
        int topVal = st.top();
        st.pop();
        if (!minSt.empty() && topVal == minSt.top()) {
            minSt.pop();
        }
    }

    int top() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << "\n"; // 3
    s.push(2);
    s.push(1);
    cout << s.getMin() << "\n"; // 1
    s.pop();
    cout << s.getMin() << "\n"; // 2
    cout << s.top() << "\n";    // 2
}
/*st → keeps all values.
minSt → keeps the running minimum.
Whenever you push a value smaller or equal to current min → push into minSt.
Whenever you pop and it equals min → pop from minSt.*/