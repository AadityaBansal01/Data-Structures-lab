#include <iostream>
using namespace std;
#define MAX 4

int main() {
    int i, j, k = 0, size = (MAX*(MAX+1))/2;
    int a[size];

    cout << "Enter " << size << " upper triangular elements (row major):\n";
    for (i = 0; i < size; i++) cin >> a[i];

    cout << "\nThe upper triangular matrix is:\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i <= j) cout << a[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
