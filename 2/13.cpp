#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            // shift right from end to i+1
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            // put extra 2 after current 2
            if (i + 1 < n) arr[i + 1] = 2;
            i++; // skip next because it's the duplicated 2
        }
    }
}

int main() {
    int arr[] = {1,2,3,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Result: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
