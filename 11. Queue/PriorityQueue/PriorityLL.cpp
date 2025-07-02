#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head || val > head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data >= val)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteMax() {
        if (!head) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
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
