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

int n;
vector<ll> bit(maxn + 1, 0); // BIT for maximum
void update(int i, ll v) {
    for (; i <= n; i += i & -i)
        bit[i] = max(bit[i], v);
}

ll query(int i) {
    // Query the maximum value in the BIT up to index i
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    vector<int> h(n), a(n);
    forup(i, 0, n) cin >> h[i];
    forup(i, 0, n) cin >> a[i];
    forup(i, 0, n) {
        ll val = query(h[i] - 1) + a[i];
        update(h[i], val);
    }
    cout << query(n) << el;
}