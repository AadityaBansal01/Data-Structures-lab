#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> q) {
    stack<int> s;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        if (q.front() == expected) {
            q.pop();
            expected++;
        } else if (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        } else {
            s.push(q.front());
            q.pop();
        }
    }

    // Check the stack after queue is empty
    while (!s.empty() && s.top() == expected) {
        s.pop();
        expected++;
    }

    return expected == n + 1;
}

int main() {
    queue<int> q;
    // Example input: Queue of first n natural numbers in random order
    int arr[] = {5, 1, 2, 3, 4};  // Change this array to test other cases
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    if (checkSorted(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
