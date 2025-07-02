#include <iostream>
using namespace std;

bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    if (isPalindrome(s))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
