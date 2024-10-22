#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA04021
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

vector<ll> fibo(100, 0);
// X[i] = X[i-2] + X[i-1], i > 2
char findkthchar(ll n, ll k)
{
    if (n == 1)
        return '0';
    if (n == 2)
        return '1';
    if (k <= fibo[n - 2])
        return findkthchar(n - 2, k); // search the left half
    else
        return findkthchar(n - 1, k - fibo[n - 2]); // search the right half
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);
    
    fibo[1] = 1;
    forup(i, 2, 93)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    tests()
    {
        ll n, k; 
        cin >> n >> k;
        cout << findkthchar(n, k) << el;
    }
}