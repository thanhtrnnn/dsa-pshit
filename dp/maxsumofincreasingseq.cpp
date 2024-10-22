#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

int maxsum(vector<int> &a, int n)
{
    // sum of lis with length 0 -> n, which includes a[i]
    vector<int> dp(n, 0);
    int res = 0;
    forup(i, 0, n)
    {
        // IMPORTANT: dp[i] at least equals to a[i]
        dp[i] = a[i];
        // consider the whole seq 0 -> i
        fordown(j, i - 1, 0)
        {
            if (a[j] < a[i])
                // update dp[i]
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
        // update final result
        res = max(res, dp[i]);
    }
    // print(dp, 0, n);
    return res;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        cout << maxsum(a, n) << el;
    }
}