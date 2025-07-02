#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    unordered_set<int> us;
    int n, val;
    cout << "Enter number of elements for unordered_set: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        us.insert(val);
    }
    cout << "\nUnordered Set Contents:\n";
    for (auto v : us) cout << v << " ";
    return 0;
}
