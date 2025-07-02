#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    void push(int d) {
        if (top >= MAX - 1) {
            cout << "\nStack Full!";
            return;
        }
        arr[++top] = d;
        cout << "\nSuccess!";
    }

    void pop() {
        if (top == -1) {
            cout << "\nStack Empty!";
            return;
        }
        cout << "\nPopped: " << arr[top--];
    }

    void peek() {
        if (top == -1) {
            cout << "\nStack Empty!";
            return;
        }
        cout << "\nTop Element is: " << arr[top];
    }

    void display() {
        if (top == -1) {
            cout << "\nStack Empty!";
            return;
        }
        cout << "\nStack Elements in Top-Down Order are:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
        cout << "Success!";
    }
};

int main() {
    int ch = 0;
    Stack s;
    while (ch != 5) {
        cout << "\n\nEnter the choice: ";
        cout << "\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: {
                int d;
                cout << "Enter the data: ";
                cin >> d;
                s.push(d);
                break;
            }
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "\nExited...!";
                break;
            default:
                cout << "\nInvalid Input!";
                break;
        }
    }
    return 0;
}
