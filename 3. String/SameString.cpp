#include <iostream>
using namespace std;

bool areStringsSame(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if (areStringsSame(s1, s2))
        cout << "The strings are the SAME. \n";
    else
        cout << "The strings are DIFFERENT. \n";

    return 0;
}
