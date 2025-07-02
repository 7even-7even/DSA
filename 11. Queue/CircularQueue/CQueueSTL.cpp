#include <iostream>
#include <deque>
using namespace std;

class CircularQueueSTL {
    deque<int> dq;
    int maxSize;

public:
    CircularQueueSTL(int s) {
        maxSize = s;
    }

    void enqueue(int val) {
        if (dq.size() == maxSize) {
            cout << "\nQueue Full!";
            return;
        }
        dq.push_back(val);
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (dq.empty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nDequeued: " << dq.front();
        dq.pop_front();
    }

    void display() {
        if (dq.empty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nQueue: ";
        for (int val : dq)
            cout << val << " | ";
    }
};

int main() {
    CircularQueueSTL q(5);
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
