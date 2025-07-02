#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    if (arr.empty()) {
        cout << "\nEmpty Array!";
        return;
    }

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "\nSorted Array is: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n;
    cout << "\nArray Size: ";
    cin >> n;

    cout << "\nInput Array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    selectionSort(arr);

    return 0;
}
