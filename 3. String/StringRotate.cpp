#include <iostream>
using namespace std;

string leftRotate(string str, int k) {
    int n = str.length();
    k = k % n;

    string rotated = "";

    for (int i = k; i < n; i++) {
        rotated += str[i];
    }
    for (int i = 0; i < k; i++) {
        rotated += str[i];
    }

    return rotated;
}

string rightRotate(string str, int k) {
    int n = str.length();
    k = k % n;

    string rotated = "";

    for (int i = n - k; i < n; i++) {
        rotated += str[i];
    }
    for (int i = 0; i < n - k; i++) {
        rotated += str[i];
    }

    return rotated;
}

int main() {
    string str;
    int k, choice;

    cout << "Enter the string: ";
    cin >> str;

    cout << "Enter number of positions to rotate: ";
    cin >> k;

    cout << "Choose rotation direction:\n1. Left\n2. Right\nEnter choice: ";
    cin >> choice;

    string result;

    if (choice == 1)
        result = leftRotate(str, k);
    else if (choice == 2)
        result = rightRotate(str, k);
    else {
        cout << "Invalid choice." << endl;
        return 0;
    }

    cout << "Rotated string: " << result << endl;

    return 0;
}
