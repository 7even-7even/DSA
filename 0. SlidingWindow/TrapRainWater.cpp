// Trapping Rain Water (LeetCode #42)
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i)
        left_max[i] = max(left_max[i-1], height[i]);
    right_max[n-1] = height[n-1];
    for (int i = n-2; i >= 0; --i)
        right_max[i] = max(right_max[i+1], height[i]);
    int water = 0;
    for (int i = 0; i < n; ++i)
        water += min(left_max[i], right_max[i]) - height[i];
    return water;
}

int main() {
    int n;
    cout << "Enter number of heights: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; ++i) cin >> height[i];
    cout << "Total trapped rain water: " << trap(height) << endl;
    return 0;
}
