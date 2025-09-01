#include <iostream>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    int count[26] = {0};
    for (char c : s1) count[c - 'a']++;
    for (char c : s2) count[c - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main() {
    string str1 = "triangle", str2 = "integral";
    if (areAnagrams(str1, str2)) cout << "Yes";
    else cout << "No";
}
