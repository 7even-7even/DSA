#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ch;
    queue<int> q;
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
            q.push(a);
            break;

        case 2:
            int temp = q.back();
            q.pop();
            cout << temp;
            break;

        case 3:
            cout << q.back();
            break;

        case 4:
            while (!q.empty())
            {
                cout << q.front() << " | ";
                q.pop();
            }
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