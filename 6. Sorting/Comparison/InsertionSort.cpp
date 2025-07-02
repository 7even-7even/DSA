#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "\nSorted Array is: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Array Size: ";
    cin >> n;

    cout << "Input Array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    insertionSort(arr);
    return 0;
}
