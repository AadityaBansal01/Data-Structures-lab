#include <iostream>
#include <string>
using namespace std;

string canSplit(const string &S) {
    int freq[26] = {0};
    for (char ch : S) {
        freq[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= 3) return "Yes";
    }
    return "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        cout << canSplit(S) << "\n";
    }
    return 0;
}
/*Turns out, the simplest way is to just check if any character occurs at least 3 times. Why? Because:
You can let B be that single repeated character (occurring at least thrice).
Put one occurrence in A, one in B, and one in C.

.
*/