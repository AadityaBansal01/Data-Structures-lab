#include <iostream>
#include <string>
using namespace std;

// Function to sort strings in alphabetical order
void sortStrings(string arr[], int n) {
    string temp;
    // Using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Compare strings lexicographically
            if (arr[i] > arr[j]) {
                // Swap if out of order
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    string arr[100];  // Array to store strings (max 100)

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort function call
    sortStrings(arr, n);

    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}