#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "Vector is empty.\n";
        return;
    }

    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int linearSearch(const vector<int>& v, int key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key)
            return i;
    }
    return -1;
}

int main() {
    vector<int> v;
    int n, element;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> element;
        v.push_back(element);
    }

    printVector(v);
    cout << "Size: " << v.size() << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    cout << "\nPopping last element...\n";
    v.pop_back();
    printVector(v);

    int pos, val;

    cout << "\nInsert element at specific position:\n";
    cout << "Enter element to insert: ";
    cin >> val;
    cout << "Enter position (0-based index): ";
    cin >> pos;

    if (pos >= 0 && pos <= v.size())
        v.insert(v.begin() + pos, val);
    else
        cout << "Invalid position.\n";

    printVector(v);

    cout << "\nDelete element by index:\n";
    cout << "Enter index to delete: ";
    cin >> pos;

    if (pos >= 0 && pos < v.size())
        v.erase(v.begin() + pos);
    else
        cout << "Invalid index.\n";

    printVector(v);

    cout << "\nDelete element by value:\n";
    cout << "Enter value to delete: ";
    cin >> val;

    int index = linearSearch(v, val);
    if (index != -1) {
        v.erase(v.begin() + index);
        cout << "Element deleted.\n";
    } else {
        cout << "Element not found.\n";
    }

    printVector(v);

    cout << "\nSearch for an element:\n";
    cout << "Enter value to search: ";
    cin >> val;

    index = linearSearch(v, val);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found.\n";

    return 0;
}
