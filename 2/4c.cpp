#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int i = 0, j = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    cout << "String after deleting vowels: " << str;
    return 0;
}

