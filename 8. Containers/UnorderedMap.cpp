#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string, int> um;
    int n, val;
    string key;
    cout << "Enter number of elements for unordered_map: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter key and value: ";
        cin >> key >> val;
        um[key] = val;
    }
    cout << "\nUnordered Map Contents:\n";
    for (auto &it : um) cout << it.first << " => " << it.second << endl;
    return 0;
}
