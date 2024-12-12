#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04003
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"
#define mod                 (int)(123456789)

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

ll binpow(ll n, ll k)
{
    if (k == 1)
        return n;
    ll res = binpow(n, k / 2);
    if (k % 2)
        return res % mod * res % mod * n % mod;
    else
        return res % mod * res % mod;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        ll n; cin >> n;
        cout << binpow(2, n - 1) << el;
    }
}