#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q; 
    unordered_map<char,int> freq;  // store frequency of characters

    for (char ch : str) {
        // push char to queue and update frequency
        q.push(ch);
        freq[ch]++;

        // remove all characters from front which are repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // print first non-repeating or -1
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters (with spaces): ";
    getline(cin, input);

    // remove spaces to match your sample I/P
    string s = "";
    for (char c : input) {
        if (c != ' ') s += c;
    }

    firstNonRepeating(s);
    return 0;
}