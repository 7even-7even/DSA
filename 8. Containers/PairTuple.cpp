#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
int main() {
    pair<int, string> p;
    int x;
    string y;
    cin >> x >> y;
    p = make_pair(x, y);
    cout << p.first << " " << p.second << endl;

    int a;
    string b;
    float c;
    cin >> a >> b >> c;
    tuple<int, string, float> t = make_tuple(a, b, c);
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return 0;
}