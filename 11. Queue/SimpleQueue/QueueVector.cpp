#include <iostream>
#include <vector>
using namespace std;

class Queue {
    vector<int> v;

public:
    void enqueue(int val) {
        v.push_back(val);
        cout << "\nEnqueued: " << val;
    }

    void dequeue() {
        if (v.empty()) {
            cout << "\nQueue Empty!";
            return;
        }
        int temp = v.front();
        v.erase(v.begin()); 
        cout << "\nDequeued: " << temp;
    }

    void peek() {
        if (v.empty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nFront Element: " << v.front();
    }

    void display() {
        if (v.empty()) {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nQueue: ";
        for (int x : v)
            cout << x << " | ";
    }
};

int main()
{
    int ch;
    Queue q;

    while (ch != 5)
    {
        cout << "\nEnter Your Choice For Queue Operations: ";
        cout << "\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Display \n5. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int a;
            cout << "\nEnter the Element to be inserted: ";
            cin >> a;
            q.enqueue(a);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "\nExited...!";
            break;

        default:
            cout << "\nInvalid Option!";
            break;
        }
    }
    return 0;
}