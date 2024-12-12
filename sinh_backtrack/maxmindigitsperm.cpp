#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02035
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "; cout << el
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
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

    int k, n; 
    cin >> n >> k;
    vector<string> S(n);
    forup(i, 0, n) cin >> S[i];

    vector<int> M(k);
    iota(all(M), 0);
    int res = INT_MAX;
    do {
        int minn = INT_MAX, maxx = INT_MIN;
        for (auto s : S) 
        {
            string x;
            forup(i, 0, k)
                x += s[M[i]];
            minn = min(minn, stoi(x));
            maxx = max(maxx, stoi(x));
        }
        res = min(res, maxx - minn);
    } 
    while (next_permutation(all(M)));
    cout << res << el;
}