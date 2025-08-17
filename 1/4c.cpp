#include <iostream>
using namespace std;

// Function to print transpose of matrix
void transpose(int a[10][10], int r, int c) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r, c;
    int a[10][10];

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose Matrix:\n";
    transpose(a, r, c);

    return 0;
}