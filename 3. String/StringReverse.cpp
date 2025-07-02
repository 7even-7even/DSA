#include <iostream>
using namespace std;

string reverseString(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    return str;
}

int main() {
    string s;

    cout << "Enter a string to reverse: ";
    cin >> s;

    string reversed = reverseString(s);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
