#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(5e6)
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

int n;
vector<ll> bit(maxn, 0); // BIT lưu số dãy kết thúc tại mỗi giá trị
void update(int i, int v) {
    // cập nhật BIT tại vị trí i với giá trị v
    for (; i < maxn; i += i & -i)
        bit[i] = (bit[i] + v) % mod;
}

int sum(int i) {
    // số dãy kết thúc bằng giá trị <= i
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res % mod;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> n >> k;
    vector<int> a(n);
    forup(i, 0, n) {
        cin >> a[i];
        ++a[i]; // to avoid 0 index in BIT
    }

    // count increasing seq of length k
    // dp[i] = số dãy kết thúc tại i
    vector<int> dp(n, 1);
    forup(j, 2, k + 1) {
        fill(all(bit), 0);
        forup(i, 0, n) {
            update(a[i], dp[i]); // đưa số lượng dãy j-1, kết thúc ở giá trị a[i] vào BIT.
            dp[i] = sum(a[i] - 1); // lấy tổng số dãy j-1, kết thúc ở giá trị nhỏ hơn a[i] 
        }
    }
    // print(dp, 0, n);
    // cộng tất cả các dãy kết thúc tại i, dài đúng k
    cout << accumulate(all(dp), 0LL) % mod << el;
}