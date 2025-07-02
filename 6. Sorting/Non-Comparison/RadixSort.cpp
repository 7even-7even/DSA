#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    vector<int> arr;
    int n;
    cout << "\nEnter the Size of Input Array: ";
    cin >> n;
    arr.resize(n);
    cout << "\nEnter the Input Array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr);

    cout << "\nSorted Array using Radix Sort:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
