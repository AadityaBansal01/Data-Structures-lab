#include <iostream>
using namespace std;

// Function to multiply two matrices
// a -> first matrix of size r1 x c1
// b -> second matrix of size c1 x c2
// res -> resultant matrix of size r1 x c2
void multiply(int a[10][10], int b[10][10], int res[10][10], int r1, int c1, int c2) {
    // Initialize result matrix with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    // Each cell res[i][j] = sum of (a[i][k] * b[k][j]) for k = 0 to c1-1
    for (int i = 0; i < r1; i++) {         // Loop through rows of first matrix
        for (int j = 0; j < c2; j++) {     // Loop through columns of second matrix
            for (int k = 0; k < c1; k++) { // Loop through elements of row (a) and column (b)
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[10][10], b[10][10], res[10][10];
    int r1, c1, r2, c2;

    // Input dimensions of first matrix
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    // Input dimensions of second matrix
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    // Matrix multiplication rule:
    // Number of columns of first matrix (c1) must equal number of rows of second matrix (r2)
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    // Input first matrix
    cout << "Enter elements of first matrix (" << r1 << "x" << c1 << "):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of second matrix (" << r2 << "x" << c2 << "):\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }

    // Multiply matrices
    multiply(a, b, res, r1, c1, c2);

    // Print result
    cout << "Resultant matrix (" << r1 << "x" << c2 << "):\n";
    printMatrix(res, r1, c2);

    return 0;
}