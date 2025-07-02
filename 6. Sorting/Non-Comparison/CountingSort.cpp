#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - minVal]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

int main() {
    int n;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "\nEnter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr);

    cout << "\nSorted Array using Counting Sort:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
