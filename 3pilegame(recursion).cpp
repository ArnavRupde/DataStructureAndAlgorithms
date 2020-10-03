#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 1e5 + 1;
vector<string> op(mxN);

vector<char> ans;

bool recur(int a, int b, int c, int n, int i)
{
    //    cout<<a<<" "<<b<<" "<<c<<endl;
    if (i == (n) && a >= 0 && b >= 0 && c >= 0)
        return true;
    if (i >= (n) && (a < 0 || b < 0 || c < 0))
        return false;
    if (a < 0 || b < 0 || c < 0)
        return false;
    string s = op[i];
    if (s == "AB")
    {
        if (recur(a + 1, b - 1, c, n, i + 1))
        {
            ans.push_back('A');
            return true;
        }
        if (recur(a - 1, b + 1, c, n, i + 1))
        {
            ans.push_back('B');
            return true;
        }
    }
    if (s == "AC")
    {
        if (recur(a + 1, b, c - 1, n, i + 1))
        {
            ans.push_back('A');
            return true;
        }
        if (recur(a - 1, b, c + 1, n, i + 1))
        {
            ans.push_back('C');
            return true;
        }
    }
    if (s == "BC")
    {
        if (recur(a, b + 1, c - 1, n, i + 1))
        {
            ans.push_back('B');
            return true;
        }
        if (recur(a, b - 1, c + 1, n, i + 1))
        {
            ans.push_back('C');
            return true;
        }
    }
    return false;
}
signed main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> op[i];
    }
    if (!recur(a, b, c, n, 0))
        cout << "No" << endl;
    else
    {
        reverse(ans.begin(), ans.end());
        cout << "Yes" << endl;
        for (char chh : ans)
            cout << chh << endl;
    }
}