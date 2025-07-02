#include <iostream>
#include <vector>
using namespace std;

void reverseVector(vector<int>& v) {
    int start = 0, end = v.size() - 1;
    while (start < end) {
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
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

    cout << "Original Vector: ";
    printVector(v);

    reverseVector(v);

    cout << "Reversed Vector: ";
    printVector(v);

    return 0;
}
