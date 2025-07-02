#include <iostream>
using namespace std;

string concatenateStrings(string str1, string str2) {
    string result = str1;

    for (int i = 0; i < str2.length(); i++) {
        result += str2[i];
    }

    return result;
}

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    string concatenated = concatenateStrings(s1, s2);

    cout << "Concatenated string: " << concatenated << endl;

    return 0;
}
