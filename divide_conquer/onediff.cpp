#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04017
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<ll> a(n), b(n - 1);
        int res = 0, check = 1;
        forup(i, 0, n) cin >> a[i];
        forup(i, 0, n - 1) 
        {
            cin >> b[i];
            if (a[i] != b[i] && check)
            {
                res = i + 1;
                check = false;
            }
        }
        if (!check)
            cout << res << el;
        else
            cout << n << el;
    }
}