#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ans(n, 0); 
    stack<int> st; // stores indices, not values

    for (int i = 0; i < n; i++) {
        // While current temp is hotter than the temp at stack's top index
        while (!st.empty() && T[i] > T[st.top()]) {
            int idx = st.top(); 
            st.pop();
            ans[idx] = i - idx; // days waited
        }
        st.push(i); // store current index
    }
    return ans;
}

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(T);

    for (int x : ans) cout << x << " ";
    cout << endl;
}
