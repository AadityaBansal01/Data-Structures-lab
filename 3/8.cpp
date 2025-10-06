#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1); // default -1
    stack<int> st;          // stack to keep candidates

    // Traverse from right → left
    for (int i = n - 1; i >= 0; i--) {
        // Pop all smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            res[i] = st.top(); // next greater element
        }

        // push current element as candidate
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreaterElements(arr);

    for (int x : res) cout << x << " ";
    cout << endl;
}
