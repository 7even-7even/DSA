#include <iostream>
#include <map>
using namespace std;
int main() {
    multimap<int, string> mm;
    int n, key;
    string val;
    cout << "Enter number of elements for multimap: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter key and value: ";
        cin >> key >> val;
        mm.insert({key, val});
    }
    cout << "\nMultimap Contents:\n";
    for (auto &it : mm) cout << it.first << " => " << it.second << endl;
    return 0;
}