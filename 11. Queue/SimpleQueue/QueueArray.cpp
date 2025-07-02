#include <bits/stdc++.h>
using namespace std;
#define SIZE 5
class Queue
{
    int arr[SIZE];
    int front = 0;
    int rear = 0;

public:
    void enqueue(int a)
    {
        if (front == SIZE)
        {
            cout << "\nQueue Full!";
            return;
        }
        arr[front] = a;
        front++;
        cout << "\nSuccess!";
        return;
    }

    void dequeue()
    {
        if (rear == front)
        {
            cout << "\nQueue Empty!";
            return;
        }
        int temp = arr[rear];
        rear++;
        cout << "\nDequeued Element: " << temp;
        return;
    }

    void peek()
    {
        if (front == rear)
        {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nThe Elemet at front is: " << arr[rear];
        return;
    }

    void display()
    {
        if (front == rear)
        {
            cout << "\nQueue Empty!";
            return;
        }
        cout << "\nThe elements of Queue are: " << endl;
        for (int i = rear; i < front; i++)
        {
            cout << arr[i] << " | ";
        }
        cout << endl;
        return;
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