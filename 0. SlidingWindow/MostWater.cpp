// Container With Most Water (LeetCode #11)
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        max_area = max(max_area, h * w);
        if (height[left] < height[right])
            ++left;
        else
            --right;
    }
    return max_area;
}

int main() {
    int n;
    cout << "Enter number of heights: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; ++i) cin >> height[i];
    cout << "Maximum water that can be contained: " << maxArea(height) << endl;
    return 0;
}
