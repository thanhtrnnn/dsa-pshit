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
#define maxn                (int)(2e5 + 7)
#define len(a)              (int)a.size()
#define el                  "\n"

void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif
}

ll dp[maxn][2][110];
int d;
string s;

ll f (int idx, bool smaller, int sum) {
    if(idx < 0) return sum == 0;
    ll &memo = dp[idx][smaller][sum];
    if(memo != -1) return memo;
    memo = 0;
    int lim = smaller ? 9 : s[idx] - '0';
    for(int i = 0; i <= lim; ++i){
        memo += f(idx - 1, smaller || (i < lim), (sum + i) % d);
        memo %= mod;
    }
    return memo;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> s >> d;
    int n = len(s);
    // dp[i][j][k] = số số trong [0, i], có tổng chữ số % d = k, 
    // với j = 0 có giới hạn, 1 không giới hạn
    
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1; // base case
    
    // SOLUTION 1: bottom-up DP
    // forup(i, 0, n) {
    //     forup(j, 0, 2) {
    //         int lim = j ? 9 : (s[i] - '0');
    //         forup(k, 0, d) {
    //             if (!dp[i][j][k]) 
    //                 continue;
    //             forup(x, 0, lim + 1) {
    //                 // chuyển sang không giới hạn nếu x < lim
    //                 int new_j = j || (x < lim);
    //                 int new_k = (k + x) % d;
    //                 dp[i + 1][new_j][new_k] = (dp[i + 1][new_j][new_k] + dp[i][j][k]) % mod;
    //             }
    //         }
    //     }
    // }

    // cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << el;

    // SOLUTION 2: top-down DP
    reverse(all(s));
    memset(dp, -1, sizeof(dp));
    cout << (f(n - 1, 0, 0) - 1 + mod) % mod << el;
}