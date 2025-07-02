#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "\nSuccess!";
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "\nSuccess!";
    }

    void insertAtPosition(int val, int pos)
    {

        if (pos == 1)
        {
            insertAtBeginning(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 1;

        while (count != pos - 1 && temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            cout << "\nPosition Out Of Bounds";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "\nSuccess";
    }

    void deleteAtBeginning()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "\nSuccess!";
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "\nEmpty List!";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "\nSuccess!";
            return;
        }

        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        cout << "\nSuccess!";
    }

    void deleteByValue(int val)
    {
        if (head == NULL)
        {
            cout << "Empty List!";
            return;
        }

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "\nSuccess!";
            return;
        }

        Node *prev = NULL;
        Node *curr = head;

        while (curr->data != val && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            cout << "\nPosition Out Of Bound!";
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "\nSuccess";
    }

    void deleteByPosition(int pos)
    {
        if (pos == 1)
        {
            deleteAtBeginning();
        }

        if (head == NULL)
        {
            cout << "Empty List!";
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp != NULL && count != pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "\nPosition Out Of Bound!";
            return;
        }

        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "\nSucess!";
    }

    void display()
    {

        if (head == NULL)
        {
            cout << "Empty List!";
            return;
        }
        
        cout << "\nBelow is the LinkedList: ";

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << "\nSuccess!";
    }

    void reversal()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "\nSuccess!";
    }
};

int main()
{
    int ch;
    LinkedList ll;
    do
    {
        cout << "\nSelect the Operation on Linked List:";
        cout << "\n1. Insertion \n2. Deletion  \n3. Reversal  \n4. Display \n5. Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int val;
            int subch;
            cout << "\nInsertion at ? \n1. Beginning \n2. End \n3. Specified Position\n";
            cin >> subch;

            cout << "Enter the value: ";
            cin >> val;

            switch (subch)
            {
            case 1:
                ll.insertAtBeginning(val);
                break;

            case 2:
                ll.insertAtEnd(val);
                break;

            case 3:
                int pos;
                cout << "\nEnter the position: ";
                cin >> pos;
                if (pos < 0)
                {
                    cout << "\nInvalid Input!";
                    break;
                }
                ll.insertAtPosition(val, pos);
                break;

            default:
                cout << "\nExited...";
                break;
            }
            break;
        }

        case 2:
        {
            int subch;
            cout << "\nDelete at \n1. Begining \n2. End \n3. By Value \n4. By Position\n";
            cin >> subch;
            switch (subch)
            {
            case 1:
                ll.deleteAtBeginning();
                break;

            case 2:
                ll.deleteAtEnd();
                break;

            case 3:
                int val;
                cout << "\nEnter the Value to be deleted: ";
                cin >> val;
                ll.deleteByValue(val);
                break;
            case 4:
                int pos;
                cout << "\nEnter the postion form where the node to be deleted: ";
                cin >> pos;
                ll.deleteByPosition(pos);
                break;

            default:
                cout << "\nExited...";
                break;
            }
            break;
        }

        case 3:
            ll.reversal();
            break;

        case 4:
            ll.display();
            break;

        default:
            cout << "\nExited...";
            break;
        }
    } while (ch != 5);
    return 0;
}
