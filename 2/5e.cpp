#include <iostream>
using namespace std;
#define MAX 4

// function to map (i,j) -> index in 1D array (upper triangle row-major)
int getIndex(int i, int j) {
    return (i * MAX) - (i * (i - 1)) / 2 + (j - i);
}

int main() {
    int i, j;
    int size = (MAX * (MAX + 1)) / 2; // number of elements in symmetric matrix
    int a[size];

    cout << "Enter " << size << " elements of symmetric matrix (upper triangle row-major):\n";
    for (i = 0; i < size; i++) cin >> a[i];

    cout << "\nThe symmetric matrix is:\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i <= j)  // upper triangle element
                cout << a[getIndex(i, j)] << " ";
            else          // symmetry: a[i][j] = a[j][i]
                cout << a[getIndex(j, i)] << " ";
        }
        cout << endl;
    }
    return 0;
}
