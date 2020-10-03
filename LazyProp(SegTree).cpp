// Assign l to r-1 with v and return a[i]..

#include <bits/stdc++.h>
using namespace std;

struct segtree
{
    vector<long long> operations;
    int size;
    void init(int n)
    {
        size = 1;
        while (size < 2 * n)
            size *= 2;
        operations.assign(2 * size, 0);
    }

    long long operation(long long a, long long b)
    {
        if (b == LLONG_MAX)
            return a;
        return b;
    }

    void apply_operations(long long &a, long long b)
    {
        a = operation(a, b);
    }

    void propagate(int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return;
        apply_operations(operations[2 * x + 1], operations[x]);
        apply_operations(operations[2 * x + 2], operations[x]);
        operations[x] = LLONG_MAX;
    }

    void update_max(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            apply_operations(operations[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        update_max(l, r, v, 2 * x + 1, lx, m);
        update_max(l, r, v, 2 * x + 2, m, rx);
    }

    void update_max(int l, int r, int v)
    {
        update_max(l, r, v, 0, 0, size);
    }

    int get(int i, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (rx - lx == 1)
        {
            return operations[x];
        }
        int m = (lx + rx) / 2;
        int res = 0;
        if (i < m)
            res = get(i, 2 * x + 1, lx, m);
        else
            res = get(i, 2 * x + 2, m, rx);
        return res;
    }

    int get(int i)
    {
        return get(i, 0, 0, size);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    segtree st;
    st.init(n);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.update_max(l, r, v);
        }
        else
        {
            int i;
            cin >> i;
            cout << st.get(i) << endl;
        }
    }
}