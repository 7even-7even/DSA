#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int ch, val;

    while (true) {
        cout << "\n1. Insert\n2. Delete Max\n3. Display\n4. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cin >> val;
                pq.push(val);
                break;
            case 2:
                if (pq.empty())
                    cout << "Underflow\n";
                else
                    pq.pop();
                break;
            case 3:
                if (pq.empty())
                    cout << "Priority Queue is empty\n";
                else {
                    priority_queue<int> temp = pq;
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
