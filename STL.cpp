#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // copy
    vector<int> copy_v(5);
    copy(v.begin(), v.end(), copy_v.begin());
    cout << "Copied Vector: ";
    for (int i : copy_v) cout << i << " "; // Output: 1 2 3 4 5
    cout << endl;

    // fill
    fill(copy_v.begin(), copy_v.end(), 9);
    cout << "Filled with 9: ";
    for (int i : copy_v) cout << i << " "; // Output: 9 9 9 9 9
    cout << endl;

    // transform
    transform(v.begin(), v.end(), copy_v.begin(), [](int x) { return x * x; });
    cout << "Squared values: ";
    for (int i : copy_v) cout << i << " "; // Output: 1 4 9 16 25
    cout << endl;

    // replace
    replace(copy_v.begin(), copy_v.end(), 25, 100);
    cout << "Replaced 25 with 100: ";
    for (int i : copy_v) cout << i << " "; // Output: 1 4 9 16 100
    cout << endl;

    // swap
    int a = 5, b = 10;
    swap(a, b);
    cout << "Swapped values: a = " << a << ", b = " << b << endl; // Output: a = 10, b = 5

    // reverse
    reverse(v.begin(), v.end());
    cout << "Reversed vector: ";
    for (int i : v) cout << i << " "; // Output: 5 4 3 2 1
    cout << endl;

    // rotate
    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "Rotated vector (start+2): ";
    for (int i : v) cout << i << " "; // Output: 3 2 1 5 4
    cout << endl;

    // remove
    v.push_back(2); // {3, 2, 1, 5, 4, 2}
    v.erase(remove(v.begin(), v.end(), 2), v.end());
    cout << "Removed 2: ";
    for (int i : v) cout << i << " "; // Output: 3 1 5 4
    cout << endl;

    // unique
    vector<int> uniq = {1, 1, 2, 2, 3, 3};
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
    cout << "Unique values: ";
    for (int i : uniq) cout << i << " "; // Output: 1 2 3
    cout << endl;

    // max_element, min_element
    cout << "Max: " << *max_element(v.begin(), v.end()) << endl; // Output: 5
    cout << "Min: " << *min_element(v.begin(), v.end()) << endl; // Output: 1

    // accumulate
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << endl; // Output: 13

    // count
    cout << "Count of 1: " << count(v.begin(), v.end(), 1) << endl; // Output: 1

    // find
    auto it = find(v.begin(), v.end(), 5);
    cout << "5 is at index: " << distance(v.begin(), it) << endl; // Output: index of 5

    // is_permutation
    vector<int> vp = {3, 1, 5, 4};
    cout << "Is permutation: " << boolalpha << is_permutation(v.begin(), v.end(), vp.begin()) << endl; // Output: true

    // is_sorted
    cout << "Is sorted: " << boolalpha << is_sorted(v.begin(), v.end()) << endl; // Output: false

    // partial_sum
    vector<int> partial = {1, 2, 3, 4};
    partial_sum(partial.begin(), partial.end(), partial.begin());
    cout << "Partial sum: ";
    for (int i : partial) cout << i << " "; // Output: 1 3 6 10
    cout << endl;

    // Functors
    plus<int> add;
    cout << "Plus: " << add(10, 5) << endl; // Output: 15
    minus<int> sub;
    cout << "Minus: " << sub(10, 5) << endl; // Output: 5
    multiplies<int> mul;
    cout << "Multiply: " << mul(10, 5) << endl; // Output: 50
    divides<int> div;
    cout << "Divide: " << div(10, 5) << endl; // Output: 2
    modulus<int> mod;
    cout << "Modulus: " << mod(10, 3) << endl; // Output: 1
    negate<int> neg;
    cout << "Negate: " << neg(10) << endl; // Output: -10

    equal_to<int> eq;
    cout << "Equal: " << eq(5, 5) << endl; // true
    not_equal_to<int> neq;
    cout << "Not Equal: " << neq(5, 3) << endl; // true
    greater<int> gt;
    cout << "Greater: " << gt(5, 3) << endl; // true
    greater_equal<int> ge;
    cout << "Greater Equal: " << ge(5, 5) << endl; // true
    less<int> lt;
    cout << "Less: " << lt(3, 5) << endl; // true
    less_equal<int> le;
    cout << "Less Equal: " << le(3, 3) << endl; // true

    logical_and<bool> land;
    cout << "Logical AND: " << land(true, false) << endl; // false
    logical_or<bool> lor;
    cout << "Logical OR: " << lor(true, false) << endl; // true
    logical_not<bool> lnot;
    cout << "Logical NOT: " << lnot(true) << endl; // false

    bit_and<int> band;
    cout << "Bitwise AND: " << band(6, 3) << endl; // 2
    bit_or<int> bor;
    cout << "Bitwise OR: " << bor(6, 3) << endl; // 7
    bit_xor<int> bxor;
    cout << "Bitwise XOR: " << bxor(6, 3) << endl; // 5

    return 0;
}
