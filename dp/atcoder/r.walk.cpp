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

vector<vector<ll>> multiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    int n = size(a);
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    forup(i, 0, n) {
        forup(j, 0, n) {
            forup(k, 0, n) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>>& base, ll k) {
    int n = size(base);
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    forup(i, 0, n) res[i][i] = 1;

    while (k) {
        if (k & 1) 
            res = multiply(res, base);
        base = multiply(base, base);
        k >>= 1;
    }
    return res;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    forup(i, 0, n) {
        forup(j, 0, n) {
            cin >> a[i][j];
            res[i][j] = a[i][j];
        }
    }

    res = power(res, k);
    ll ans = 0;
    forup(i, 0, n) {
        forup(j, 0, n) {
            ans = (ans + res[i][j]) % mod;
        }
    }
    cout << ans << el;
}