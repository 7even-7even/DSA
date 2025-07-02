#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];

    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int minSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];

    int minSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        minSum = min(minSum, sum);
    }

    return minSum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximum Sum: " << maxSumSubarray(arr, k) << endl;
    cout << "Minimum Sum: " << minSumSubarray(arr, k) << endl;

    return 0;
}
