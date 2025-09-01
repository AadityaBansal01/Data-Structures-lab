#include <iostream>
using namespace std;
#define MAX 4

int main() {
    int i, j, k = 0, size = 3*MAX - 2;
    int a[size];

    cout << "Enter " << size << " tri-diagonal elements (row major):\n";
    for (i = 0; i < size; i++) cin >> a[i];

    cout << "\nThe tri-diagonal matrix is:\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i == j || i == j+1 || i+1 == j) cout << a[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
