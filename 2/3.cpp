#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return total - sum;
}

int main() {
    int arr[] = {1, 2, 3, 5};
    int n = 4;
    cout << "Missing number is: " << findMissing(arr, n);
}
