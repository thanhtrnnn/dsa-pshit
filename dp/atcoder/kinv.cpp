#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9)
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

ll dp[maxn][12] = {}; // dp[i][j] = số dãy nghịch thế kết thúc tại i, độ dài j
int n, k, a[maxn];

void update(int i, int j, ll add) {
    while (i > 0) {
        dp[i][j] = (dp[i][j] + add) % mod;
        i -= i & -i;
    }
}

ll query(int i, int j) {
    ll ret = 0;
    while (i <= 10000) {
        ret = (ret + dp[i][j]) % mod;
        i += i & -i;
    }
    return ret;
}

int main(){
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    forup(i, 1, n + 1) cin >> a[i];
    ll res = 0, t;

    forup(i, 1, n + 1) {
        forup(j, 1, k + 1) {
            // t là số dãy kết thúc tại a[i] + 1, độ dài j - 1
            t = (j == 1) ? 1 : query(a[i] + 1, j - 1);
            // thêm t dãy kết thúc tại a[i], độ dài j
            update(a[i], j, t);
            res = (j == k) ? (res + t) % mod : res;
        }
    }
    cout << res % mod << el;
}