#include <iostream>
using namespace std;

#define MAX 5  // maximum size of stack

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push element into stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack" << endl;
        }
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
        } else {
            cout << arr[top--] << " popped from stack" << endl;
        }
    }

    // Peek top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is Empty" : "Stack is NOT Empty") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Stack is Full" : "Stack is NOT Full") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 7);

    return 0;
}
