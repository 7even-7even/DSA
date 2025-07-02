#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    vector<int> arr;
    int n, target;

    cout << "Enter size of sorted array: ";
    cin >> n;

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (hasPairWithSum(arr, target))
        cout << "Pair exists with given sum.\n";
    else
        cout << "No such pair exists.\n";

    return 0;
}
