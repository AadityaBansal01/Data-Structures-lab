#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_set<int> s;  // stores only unique elements
    for(int i = 0; i < n; i++)
        s.insert(arr[i]);

    cout << "Total distinct elements = " << s.size() << endl;
    return 0;
}
