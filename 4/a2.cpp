#include <iostream>
#include <queue>
#include <climits> // for INT_MAX
using namespace std;

int main() {
    queue<int> q;

    // Step 1: Put elements in queue
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    int n = q.size(); // total elements

    // Selection sort on queue
    for (int i = 0; i < n; i++) {
        int min_val = INT_MAX;   // keep track of smallest number
        int min_index = -1;      // index of smallest number

        // Step 2: Find minimum element in unsorted part
        for (int j = 0; j < n; j++) {
            int curr = q.front(); // get front
            q.pop();              // remove it

            if (curr < min_val && j < (n - i)) {
                // update min only for the unsorted part
                min_val = curr;
                min_index = j;
            }

            q.push(curr); // put it back
        }

        // Step 3: Move that min element to rear
        for (int j = 0; j < n; j++) {
            int curr = q.front();
            q.pop();
            if (j != min_index) {
                // put back all except the min
                q.push(curr);
            }
            // if it's min_index, we skip for now
        }

        // Finally, put min value at rear
        q.push(min_val);
    }

    // Print sorted queue
    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
