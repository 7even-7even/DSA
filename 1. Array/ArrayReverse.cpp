#include <iostream>
using namespace std;

void reverseInPlace(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverseWithExtraArray(int arr[], int n) {
    int temp[100];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Reverse Method:\n";
    cout << "1. In-place Reverse\n";
    cout << "2. Reverse using Extra Array\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        reverseInPlace(arr, n);
    else if (choice == 2)
        reverseWithExtraArray(arr, n);
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
