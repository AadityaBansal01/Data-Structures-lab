#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students)
        q.push(s);

    int index = 0; // index for sandwiches
    int n = students.size();
    int count = 0; // to detect if rotation occurs without any match

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            count = 0; // reset if a sandwich is taken
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }

    return q.size(); // remaining students who can't eat
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = countStudents(students, sandwiches);
    cout << result << endl;

    return 0;
}
