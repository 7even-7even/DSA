#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int n, val;
    cout << "Enter number of elements for set: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        s.insert(val);
    }
    cout << "\nSet Contents:\n";
    for (auto v : s) cout << v << " ";
    return 0;
}