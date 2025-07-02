#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueueArray {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueueArray() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "\nQueue is Full!";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty!";
            return;
        }
        cout << "\nDequeued: " << arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty!";
            return;
        }
        cout << "\nQueue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " | ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
    }
};

int main() {
    CircularQueueArray q;
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
