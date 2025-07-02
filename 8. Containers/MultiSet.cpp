#include <iostream>
#include <set>
using namespace std;
int main() {
    multiset<int> ms;
    int n, val;
    cout << "Enter number of elements for multiset: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ms.insert(val);
    }
    cout << "\nMultiset Contents:\n";
    for (auto v : ms) cout << v << " ";
    return 0;
}
