#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> st;

    for (int x : A) {
        while (!st.empty() && st.top() >= x) st.pop();
        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(x);
    }
    return ans;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = prevSmaller(A);

    for (int x : res) cout << x << " ";
    cout << endl;
}
/*Use a stack. For each element, pop until you find a smaller one.*/