#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (float val : buckets[i])
            arr[idx++] = val;
}

int main() {
    int n;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    vector<float> arr(n);

    cout << "\nEnter elements in range [0, 1):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr);

    cout << "\nSorted Array using Bucket Sort:\n";
    for (float x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
