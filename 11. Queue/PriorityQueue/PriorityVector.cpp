#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;

public:
    void insert(int val) {
        pq.push_back(val);
        int i = pq.size() - 1;
        while (i > 0 && pq[i] > pq[i - 1]) {
            swap(pq[i], pq[i - 1]);
            i--;
        }
    }

    void deleteMax() {
        if (pq.empty()) {
            cout << "Underflow\n";
            return;
        }
        pq.erase(pq.begin());
    }

    void display() {
        for (int val : pq)
            cout << val << " ";
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
