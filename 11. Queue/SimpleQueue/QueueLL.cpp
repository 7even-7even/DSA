#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "\nQueue Empty!";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        cout << "\nDequeued: " << temp->data;
        delete temp;
    }

    void peek() {
        if (front == NULL) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nFront Element: " << front->data;
    }

    void display() {
        if (front == NULL) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nQueue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " | ";
            temp = temp->next;
        }
    }
};

int main()
{
    int ch;
    Queue q;

    while (ch != 5)
    {
        cout << "\nEnter Your Choice For Queue Operations: ";
        cout << "\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Display \n5. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int a;
            cout << "\nEnter the Element to be inserted: ";
            cin >> a;
            q.enqueue(a);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "\nExited...!";
            break;

        default:
            cout << "\nInvalid Option!";
            break;
        }
    }
    return 0;
}