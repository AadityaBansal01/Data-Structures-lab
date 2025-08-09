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
int removeDup(int a[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (a[i] == a[j]) {
                // Shift left (delete element at j)
                for (int k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--; // size reduced
            } else {
                j++;
            }
        }
    }
    return n;
}

void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - 1 - i]);
}
void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int res[10][10] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
}
void transpose(int a[10][10], int r, int c) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }
}
void sumRowCol(int a[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += a[i][j];
        cout << "Row " << i << ": " << sum << endl;
    }
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += a[i][j];
        cout << "Col " << j << ": " << sum << endl;
    }
}
