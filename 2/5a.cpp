#include <iostream>
using namespace std;
#define MAX 4

int main() {
    int i, j, k = 0, a[MAX];  

    cout << "Enter " << MAX << " diagonal elements:\n";
    for (i = 0; i < MAX; i++) cin >> a[i];

    cout << "\nThe diagonal matrix is:\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i == j) cout << a[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
