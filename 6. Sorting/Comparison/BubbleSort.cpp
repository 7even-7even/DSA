#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization
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

    bubbleSort(arr);
    return 0;
}
