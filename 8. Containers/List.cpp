#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> l;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        l.push_back(val);
    }
    for (auto v : l) cout << v << " ";
    return 0;
}