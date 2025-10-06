#include <iostream>
#include <queue> // for queue
using namespace std;

// Function to generate binary numbers from 1 to n
void generateBinary(int n) {
    // Queue will store binary numbers as strings
    queue<string> q;

    // First binary number is "1", so push it into queue
    q.push("1");

    // Loop until we generate n binary numbers
    for (int i = 1; i <= n; i++) {
        // Get the front element of queue (this is the next binary number)
        string current = q.front();
        q.pop();

        // Print it
        cout << current << " ";

        // Generate next two binary numbers by appending "0" and "1"
        // Example: if current = "1", then "10" and "11" are next
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Generate and print binary numbers from 1 to n
    generateBinary(n);

    return 0;
}
