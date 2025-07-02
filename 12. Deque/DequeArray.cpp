#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = size - 1;
        else
            front--;

        arr[front] = key;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = key;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of Deque: ";
    cin >> n;
    Deque dq(n);

    int ch, val;
    while (true) {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; dq.insertFront(val); break;
            case 2: cin >> val; dq.insertRear(val); break;
            case 3: dq.deleteFront(); break;
            case 4: dq.deleteRear(); break;
            case 5: dq.display(); break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
