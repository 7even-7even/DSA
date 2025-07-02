#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    vector<int> arr;
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Enter element to search: ";
    cin >> target;

    int result = linearSearch(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
