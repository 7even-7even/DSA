#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int ch, val;

    while (true) {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; dq.push_front(val); break;
            case 2: cin >> val; dq.push_back(val); break;
            case 3:
                if (dq.empty()) cout << "Underflow\n";
                else dq.pop_front();
                break;
            case 4:
                if (dq.empty()) cout << "Underflow\n";
                else dq.pop_back();
                break;
            case 5:
                if (dq.empty()) cout << "Deque is empty\n";
                else {
                    for (int i : dq) cout << i << " ";
                    cout << endl;
                }
                break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
