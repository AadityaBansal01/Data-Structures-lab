#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket → check top
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // no opening bracket

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // mismatch
            }
        }
    }
    // if stack empty → balanced
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression ✅\n";
    else
        cout << "Not Balanced ❌\n";

    return 0;
}
