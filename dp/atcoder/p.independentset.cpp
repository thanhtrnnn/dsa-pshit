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
#define len(a)              (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

// dp[u][0/1] = ways to color subtree u with 0/1
vector<vector<int>> dp(maxn, vector<int>(2));
vector<vector<int>> tree(maxn);
void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1; // base case
    for (int v : tree[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        dp[u][0] = (ll)dp[u][0] * dp[v][1] % mod; // if u is 0, v must be 1
        dp[u][1] = (ll)dp[u][1] * ((ll)dp[v][0] + dp[v][1]) % mod; // if u is 1, v can be 0 or 1
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    forup(i, 1, n) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // choose root = 1
    dfs(1, 0);
    cout << ((ll)dp[1][0] + dp[1][1]) % mod << el;
}