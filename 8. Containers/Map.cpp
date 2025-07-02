#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, string> m;
    int n, key;
    string val;
    cout << "Enter number of elements for map: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter key and value: ";
        cin >> key >> val;
        m[key] = val;
    }
    cout << "\nMap Contents:\n";
    for (auto &it : m) cout << it.first << " => " << it.second << endl;
    return 0;
}