#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const vector<int>& v) {
    int start = 0, end = v.size() - 1;

    while (start < end) {
        if (v[start] != v[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main() {
    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    if (isPalindrome(v))
        cout << "The vector is a palindrome." << endl;
    else
        cout << "The vector is not a palindrome." << endl;

    return 0;
}
