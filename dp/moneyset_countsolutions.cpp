#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05024
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
#define mod                 (int)(1e9 + 7)
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

    tests()
    {
        int n, k; 
        cin >> n >> k;
        vector<int> a(n), count(k + 1, 0);
        forup(i, 0, n) cin >> a[i];
        
        count[0] = 1; // solution for k = 0
        for (int x = 1; x <= k; x++)
        {
            for (auto c : a) 
            {
                if (x - c >= 0) 
                {
                    count[x] += count[x - c];
                    count[x] %= mod;
                }
            }
        }

        cout << count[k] << el;
    }
}