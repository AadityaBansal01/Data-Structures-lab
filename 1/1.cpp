#include<iostream>
using namespace std;
int arr[100], n = 0;

void create() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}
void display() {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void insert() {
    int pos, val;
    cin >> pos >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}
void del() {
    int pos;
    cin >> pos;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}
void linearSearch() {
    int key, found = 0;
    cin >> key;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) {
            cout << "Found at " << i << endl;
            found = 1;
            break;
        }
    if (!found) cout << "Not found\n";
}

int main() {
    int ch;
    while (1) {
        cout << "1.CREATE 2.DISPLAY 3.INSERT 4.DELETE 5.LINEAR SEARCH 6.EXIT\n";
        cin >> ch;
        if (ch == 1) create();
        else if (ch == 2) display();
        else if (ch == 3) insert();
        else if (ch == 4) del();
        else if (ch == 5) linearSearch();
        else break;
    }
    return 0;
}