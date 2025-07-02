#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[100];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[100];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i - k + n) % n];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100], n, k, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of positions to rotate: ";
    cin >> k;

    cout << "Choose rotation:\n1. Left\n2. Right\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        leftRotate(arr, n, k);
    else if (choice == 2)
        rightRotate(arr, n, k);
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << "Rotated array: ";
    printArray(arr, n);

    return 0;
}
