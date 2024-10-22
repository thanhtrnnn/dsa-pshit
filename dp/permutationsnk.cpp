#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05015
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define el                  "\n"
#define mod                 (int)(1e9 + 7)

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

vector<vector<ll>> dp(1001, vector<ll>(1001, 0));
void solve()
{
    dp[1][0] = dp[1][1] = 1;
    forup(i, 2, 1001)
    {
        forup(j, 0, i + 1)
        {
            if (j == 0)
                dp[i][j] = 1;
            else {
                // P(n, k) = P(n-1, k) + k*P(n-1, k-1)
                dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1];
                dp[i][j] %= mod; 
            }
        }
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    solve();
    tests()
    {
        int n, k; 
        cin >> n >> k;
        cout << dp[n][k] % mod << el;
    }
}