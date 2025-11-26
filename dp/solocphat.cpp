#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA_P049
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t = 1; cin >> t; while (t--)
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

// dp[i][j][k][l] = số số có i chữ số,
// với j = 0 có giới hạn, 1 không giới hạn
// có chia 8 dư k, hiện có l chữ số 6 và 8
ll n, dp[20][2][8][20];
vector<int> a;
ll solve(int idx, int smaller, int rem, int cnt68) {
    if (idx < 0) {
        return (rem == 0) ? cnt68 : 0;
    }

    ll &res = dp[idx][smaller][rem][cnt68];
    if (res != -1 && smaller)
        return res;

    res = 0;
    int lim = smaller ? 9 : a[idx];
    forup(d, 0, lim + 1) {
        res += solve(idx - 1, 
                    smaller || (d < a[idx]), 
                    (rem * 10 + d) % 8, 
                    cnt68 + (d == 6 || d == 8));
    }
    return res;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    // count 6 and 8 digit apperances in [1, n], n <= 10^18
    memset(dp, -1, sizeof(dp));
    tests()
    {
        cin >> n;
        a.clear();
        while (n) {
            a.push_back(n % 10);
            n /= 10;
        }
        cout << solve(len(a) - 1, 0, 0, 0);
        if (t) cout << el;
    }
}