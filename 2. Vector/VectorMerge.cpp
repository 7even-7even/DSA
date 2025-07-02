#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

vector<int> mergeVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> result;

    for (int i = 0; i < a.size(); i++)
        result.push_back(a[i]);

    for (int i = 0; i < b.size(); i++)
        result.push_back(b[i]);

    return result;
}

int main() {
    vector<int> v1, v2;
    int n1, n2, x;

    cout << "Enter number of elements in first vector: ";
    cin >> n1;
    cout << "Enter elements:\n";
    for (int i = 0; i < n1; i++) {
        cin >> x;
        v1.push_back(x);
    }

    cout << "Enter number of elements in second vector: ";
    cin >> n2;
    cout << "Enter elements:\n";
    for (int i = 0; i < n2; i++) {
        cin >> x;
        v2.push_back(x);
    }

    vector<int> merged = mergeVectors(v1, v2);

    cout << "Merged Vector: ";
    printVector(merged);

    return 0;
}
