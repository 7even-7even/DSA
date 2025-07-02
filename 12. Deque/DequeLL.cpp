#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int x) {
        Node* newNode = new Node(x);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (!front) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front)
            front->prev = nullptr;
        else
            rear = nullptr;
        delete temp;
    }

    void deleteRear() {
        if (!rear) {
            cout << "Underflow\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear)
            rear->next = nullptr;
        else
            front = nullptr;
        delete temp;
    }

    void display() {
        if (!front) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
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
