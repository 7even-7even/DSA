#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node *head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "\nSuccess!";
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
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

        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 1;

        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "\nPosition Out of Bound!";
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;

        cout << "\nSuccess!";
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "\nEmpty List!";
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
        cout << "\nSuccess!";
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "\nEmpty List!";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->prev->next = NULL;
            delete temp;
        }
        cout << "\nSuccess!";
    }

    void deleteByPosition(int pos) {
        if (head == NULL) {
            cout << "\nEmpty List!";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "\nPosition Out of Bound!";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;

        cout << "\nSuccess!";
    }

    void reversal() {
        if (!head) return;

        Node *curr = head;
        Node *temp = NULL;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != NULL)
            head = temp->prev;

        cout << "\nSuccess!";
    }

    void display() {
        if (head == NULL) {
            cout << "\nEmpty List!";
            return;
        }

        cout << "\nDoubly Linked List: ";
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main() {
    int ch;
    DoublyLinkedList dll;
    do {
        cout << "\n\nSelect the Operation on Doubly Linked List:";
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
                dll.insertAtBeginning(val);
            else if (subch == 2)
                dll.insertAtEnd(val);
            else if (subch == 3) {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                dll.insertAtPosition(val, pos);
            }
            break;
        }
        case 2: {
            int subch;
            cout << "\nDelete at? \n1. Beginning \n2. End \n3. By Position\n";
            cin >> subch;
            if (subch == 1)
                dll.deleteAtBeginning();
            else if (subch == 2)
                dll.deleteAtEnd();
            else if (subch == 3) {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                dll.deleteByPosition(pos);
            }
            break;
        }
        case 3:
            dll.reversal();
            break;
        case 4:
            dll.display();
            break;
        default:
            cout << "\nExited...";
            break;
        }
    } while (ch != 5);

    return 0;
}
