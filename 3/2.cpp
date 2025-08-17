#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // Push all characters onto stack
    for(char c : str) {
        s.push(c);
    }

    // Pop characters to form reversed string
    string rev = "";
    while(!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}
