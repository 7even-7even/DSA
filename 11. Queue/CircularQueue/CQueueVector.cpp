#include <iostream>
#include <vector>
using namespace std;

class CircularQueueVector {
    vector<int> v;
    int size, front, rear, count;

public:
    CircularQueueVector(int s) {
        size = s;
        v.resize(s);
        front = rear = count = 0;
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "\nQueue Full!";
            return;
        }
        v[rear] = val;
        rear = (rear + 1) % size;
        count++;
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nDequeued: " << v[front];
        front = (front + 1) % size;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nQueue: ";
        for (int i = 0; i < count; i++) {
            cout << v[(front + i) % size] << " | ";
        }
    }
};

int main() {
    CircularQueueVector q(5);
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
