#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CircularQueueLL {
    Node* front;
    Node* rear;

public:
    CircularQueueLL() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (rear == NULL) {
            front = rear = temp;
            rear->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "\nQueue Empty!";
            return;
        }
        if (front == rear) {
            cout << "\nDequeued: " << front->data;
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            cout << "\nDequeued: " << temp->data;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nQueue: ";
        Node* temp = front;
        do {
            cout << temp->data << " | ";
            temp = temp->next;
        } while (temp != front);
    }
};

int main() {
    CircularQueueLL q;
    int ch, val;
    do {
        cout << "\n\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: cout << "Exiting..."; break;
            default: cout << "Invalid!";
        }
    } while (ch != 4);
    return 0;
}
