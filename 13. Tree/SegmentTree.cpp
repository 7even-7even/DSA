#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int index, int l, int r)
    {
        if (l == r)
        {
            tree[index] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * index + 1, l, mid);
        build(2 * index + 2, mid + 1, r);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    void update(int index, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[index] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * index + 1, l, mid, pos, val);
        else
            update(2 * index + 2, mid + 1, r, pos, val);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int query(int index, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[index];
        int mid = (l + r) / 2;
        return query(2 * index + 1, l, mid, ql, qr) +
               query(2 * index + 2, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

int main()
{
    int n, choice;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    do
    {
        cout << "\n1. Range Query\n2. Update Value\n3. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int l, r;
            cout << "Enter range [l r]: ";
            cin >> l >> r;
            cout << "Sum = " << st.query(l, r) << endl;
        }
        else if (choice == 2)
        {
            int pos, val;
            cout << "Enter index and new value: ";
            cin >> pos >> val;
            st.update(pos, val);
        }
        else if (choice != 3)
        {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
