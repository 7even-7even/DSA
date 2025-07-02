#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node *head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "\nSuccess!";
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "\nSuccess!";
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "\nInvalid Position!";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count != pos - 1 || temp == NULL) {
            cout << "\nPosition Out of Bound!";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "\nSuccess!";
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "\nEmpty List!";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node *last = head;
            while (last->next != head)
                last = last->next;

            Node *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }
        cout << "\nSuccess!";
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "\nEmpty List!";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node *temp = head;
            Node *prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "\nSuccess!";
    }

    void deleteByPosition(int pos) {
        if (!head) {
            cout << "\nEmpty List!";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head || temp->next == NULL) {
            cout << "\nPosition Out of Bound!";
            return;
        }

        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "\nSuccess!";
    }

    void reversal() {
        if (!head || head->next == head) return;

        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        Node *tail = head;

        do {
            tail = tail->next;
        } while (tail->next != head);

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev;
        head = prev;
        tail->next = head;

        cout << "\nSuccess!";
    }

    void display() {
        if (!head) {
            cout << "\nEmpty List!";
            return;
        }

        cout << "\nCircular Linked List: ";
        Node *temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)";
    }
};

int main() {
    CircularLinkedList cll;
    int ch;

    do {
        cout << "\n\nSelect the Operation on Circular Linked List:";
        cout << "\n1. Insertion \n2. Deletion  \n3. Reversal  \n4. Display \n5. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1: {
            int val, subch;
            cout << "\nInsertion at? \n1. Beginning \n2. End \n3. Position\n";
            cin >> subch;
            cout << "Enter value: ";
            cin >> val;
            if (subch == 1)
                cll.insertAtBeginning(val);
            else if (subch == 2)
                cll.insertAtEnd(val);
            else if (subch == 3) {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                cll.insertAtPosition(val, pos);
            }
            break;
        }
        case 2: {
            int subch;
            cout << "\nDelete at? \n1. Beginning \n2. End \n3. By Position\n";
            cin >> subch;
            if (subch == 1)
                cll.deleteAtBeginning();
            else if (subch == 2)
                cll.deleteAtEnd();
            else if (subch == 3) {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                cll.deleteByPosition(pos);
            }
            break;
        }
        case 3:
            cll.reversal();
            break;
        case 4:
            cll.display();
            break;
        default:
            cout << "\nExited...";
            break;
        }

    } while (ch != 5);

    return 0;
}
