#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char c : exp) {
        // If number -> push
        if (isdigit(c)) {
            st.push(c - '0'); // convert char to int
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix = "23*5+"; 
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
}
/*Postfix = 23*5+
👉 Means (2*3)+5 = 11
*/