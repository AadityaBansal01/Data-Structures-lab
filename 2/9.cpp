#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairsWithDiffK(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 0, j = 1, count = 0;

    while (j < n) {
        int diff = arr[j] - arr[i];
        if (diff == k) {
            count++;
            i++;
            j++;
        }
        else if (diff < k) {
            j++;
        }
        else {
            i++;
        }
        if (i == j) j++; // avoid same index
    }
    return count;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;
    cout << "Count of pairs with difference " << k << " is: "
         << countPairsWithDiffK(arr, k) << endl;
    return 0;
}
