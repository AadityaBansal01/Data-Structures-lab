#include <iostream>
using namespace std;

// Function to remove duplicates in-place
int removeDup(int a[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (a[i] == a[j]) {
                // Shift elements left to overwrite duplicate
                for (int k = j; k < n - 1; k++) {
                    a[k] = a[k + 1];
                }
                n--; // Reduce size
            } else {
                j++;
            }
        }
    }
    return n;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100]; // max size
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Remove duplicates
    removeDup(a, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}