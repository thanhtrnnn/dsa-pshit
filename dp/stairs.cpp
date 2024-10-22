#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05013, DSA05034
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"
#define mod (int)(1e9 + 7)

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

    int t; cin >> t;
    while(t--)
    {
        int n, k; 
        cin >> n >> k;
        // store the result for each (0 -> n, k)
        vector<ll> dp(n + 1, 0);
        // always 1
        dp[0] = dp[1] = 1;
        forup(i, 2, n + 1)
        {
            // each step never exceeds k
            forup(j, 1, min(i, k) + 1)
            {
                // cout << dp[i - j] << ' ';
                // f(n) = f(n - 1) + ... + f(n - min(i, k))
                dp[i] += dp[i - j] % mod;
            }
            // cout << el;
        }
        cout << dp[n] % mod << el;
    }
}