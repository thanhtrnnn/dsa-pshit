#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04004
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

ll findElement(ll n, ll k)
{ 
    if (n == 1)
        return 1;
    ll half_length = pow(2, n - 1);
    if (k == half_length)
        return n; 
    else if (k < half_length)
        return findElement(n - 1, k); 
    else 
        return findElement(n - 1, k - half_length); 
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        ll n, k;
        cin >> n >> k;
        int cnt = 1;
        // while (k % 2 == 0)
        // { 
        //     ++cnt; 
        //     k /= 2;
        // }
        cout << findElement(n, k) << el;
        // cout << cnt << el;
    }
}