#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canBeSorted(vector<int>& A) {
    int n = A.size();
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end()); // what B should finally look like

    stack<int> S;
    int idx = 0; // pointer into sorted array

    for (int i = 0; i < n; i++) {
        S.push(A[i]);

        // while stack top matches the next needed element
        // keep popping if stack top == expected
        while (!S.empty() && S.top() == sortedA[idx]) {
            S.pop();
            idx++;
        }
    }

    return S.empty();
}

int main() {
    vector<int> A = {11, 5, 4, 21};
    if (canBeSorted(A)) 
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}
