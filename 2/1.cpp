#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key = 30;
    int result = binarySearch(arr, n, key);
    if (result != -1) cout << "Found at index " << result;
    else cout << "Not Found";
}
