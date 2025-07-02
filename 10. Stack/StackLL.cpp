#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "\nSuccess!";
    }

    void pop() {
        if (top == NULL) {
            cout << "\nStack is Empty!";
            return;
        }
        Node* temp = top;
        cout << "\nPopped: " << temp->data;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "\nStack is Empty!";
            return;
        }
        cout << "\nTop Element is: " << top->data;
    }

    void display() {
        if (top == NULL) {
            cout << "\nStack is Empty!";
            return;
        }
        cout << "\nStack Elements in Top-Down Order are:\n";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack s;
    int ch = 0;

    while (ch != 5) {
        cout << "\n\nEnter the choice: ";
        cout << "\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                int val;
                cout << "Enter data: ";
                cin >> val;
                s.push(val);
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
                cout << "\nInvalid choice!";
        }
    }
    return 0;
}
