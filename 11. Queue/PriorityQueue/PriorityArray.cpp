#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int n;

public:
    PriorityQueue() {
        n = 0;
    }

    void insert(int val) {
        if (n == 100) return;
        arr[n++] = val;
        for (int i = n - 1; i > 0 && arr[i] > arr[i - 1]; i--)
            swap(arr[i], arr[i - 1]);
    }

    void deleteMax() {
        if (n == 0) {
            cout << "Underflow\n";
            return;
        }
        n--;
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int ch, val;
    while (true) {
        cout << "\n1. Insert\n2. Delete Max\n3. Display\n4. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; pq.insert(val); break;
            case 2: pq.deleteMax(); break;
            case 3: pq.display(); break;
            case 4: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
