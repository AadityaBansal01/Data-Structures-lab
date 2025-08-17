#include <iostream>
using namespace std;

// Function to calculate row-wise and column-wise sums
void sumRowCol(int a[10][10], int r, int c) {
    // Row sums
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) 
            sum += a[i][j];
        cout << "Row " << i << " sum: " << sum << endl;
    }

    // Column sums
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) 
            sum += a[i][j];
        cout << "Col " << j << " sum: " << sum << endl;
    }
}

int main() {
    int r, c;
    int a[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nMatrix entered:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nRow-wise and Column-wise sums:\n";
    sumRowCol(a, r, c);

    return 0;
}