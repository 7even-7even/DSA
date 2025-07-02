#include <bits/stdc++.h>
using namespace std;

int main() {
    int ch = 0;
    stack<int> s;
    while (ch != 5) {
        cout << "\n\nEnter the choice: ";
        cout << "\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: {
                int d;
                cout << "Enter the data: ";
                cin >> d;
                s.push(d);
                break;
            }
            case 2:
                if (!s.empty())
                    s.pop();
                else
                    cout << "\nStack is Empty!";
                break;
            case 3:
                if (!s.empty())
                    cout << "\nTop Element is: " << s.top();
                else
                    cout << "\nStack is Empty!";
                break;
            case 4: {
                if (s.empty()) {
                    cout << "\nStack is Empty!";
                    break;
                }
                cout << "\nElements of Stack in Top-Down Order are: ";
                stack<int> temp = s;
                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }
                break;
            }
            case 5:
                cout << "\nExited...!";
                break;
            default:
                cout << "\nInvalid Input!";
                break;
        }
    }
    return 0;
}
