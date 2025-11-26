#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
#define maxn                (int)(1e5 + 7)
#define size(a)             (int)a.size()
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

    int n; cin >> n;
    vector<ll> a(n + 1), pre(n + 1, 0);
    forup(i, 1, n + 1) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    // min cost to merge slimes from i to j
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
    forup(i, 1, n + 1)
        dp[i][i] = 0; // cost to merge a single slime is 0

    fordown(i, n, 1) {
        forup(j, i + 1, n + 1) {
            ll best = LLONG_MAX;
            forup(k, i, j) {
                best = min(best, dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = best + pre[j] - pre[i - 1]; // cost to merge slimes from i to j
        }
    }

    cout << dp[1][n] << el; // min cost to merge all slimes
}