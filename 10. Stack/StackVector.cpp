#include <bits/stdc++.h>
using namespace std;

class Stack {
    int top;
    vector<int> arr;

public:
    Stack() { top = -1; }

    void push(int d) {
        arr.push_back(d);
        cout << "\nSuccess!";
    }

    void pop() {
        if (arr.empty()) {
            cout << "\nStack Empty!";
            return;
        }
        int top = arr.back();
        arr.pop_back();
        cout << "\nPopped: " << top;
        return;
    }

    void peek() {
        if (arr.empty()) {
            cout << "\nStack Empty!";
            return;
        }
        cout << "\nTop Element is: " << arr.back();
    }

    void display() {
        if (arr.size() == 0) {
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
