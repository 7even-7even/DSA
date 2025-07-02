#include <iostream>
using namespace std;

bool isSubstring(string mainStr, string subStr) {
    int n = mainStr.length();
    int m = subStr.length();

    if (m > n)
        return false;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (mainStr[i + j] != subStr[j])
                break;
        }
        if (j == m)
            return true;  
    }

    return false;  
}

int main() {
    string mainStr, subStr;

    cout << "Enter the main string: ";
    cin >> mainStr;

    cout << "Enter the substring to check: ";
    cin >> subStr;

    if (isSubstring(mainStr, subStr))
        cout << subStr << "' is a substring of '" << mainStr;
    else
        cout << subStr << "' is NOT a substring of '" << mainStr;

    return 0;
}
