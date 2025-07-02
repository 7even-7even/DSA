#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        if (arr[start] != arr[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isPalindrome(arr, n))
        cout << "The array is a palindrome." << endl;
    else
        cout << "The array is not a palindrome." << endl;

    return 0;
}
