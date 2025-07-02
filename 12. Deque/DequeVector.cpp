#include <iostream>
#include <vector>
using namespace std;

class Deque {
    vector<int> dq;

public:
    void insertFront(int x) {
        dq.insert(dq.begin(), x);
    }

    void insertRear(int x) {
        dq.push_back(x);
    }

    void deleteFront() {
        if (dq.empty()) {
            cout << "Underflow\n";
            return;
        }
        dq.erase(dq.begin());
    }

    void deleteRear() {
        if (dq.empty()) {
            cout << "Underflow\n";
            return;
        }
        dq.pop_back();
    }

    void display() {
        if (dq.empty()) {
            cout << "Deque is empty\n";
            return;
        }
        for (int val : dq)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    Deque d;
    int ch, val;
    while (true) {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; d.insertFront(val); break;
            case 2: cin >> val; d.insertRear(val); break;
            case 3: d.deleteFront(); break;
            case 4: d.deleteRear(); break;
            case 5: d.display(); break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
