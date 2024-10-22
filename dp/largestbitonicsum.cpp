#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05017
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "; cout << el
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

void bitonic(vector<int> &a, int n)
{
    // sum of increasing and decreasing seq with peak from 0 -> n-1
    vector<int> up(n), down(n);
    forup(i, 0, n)
    {
        up[i] = a[i];
        forup(j, 0, i)
        {
            if (a[i] > a[j])
                up[i] = max(up[i], up[j] + a[i]);
        }
    }

    fordown(i, n - 1, 0)
    {
        down[i] = a[i];
        fordown(j, n - 1, i + 1)
        {
            if (a[i] > a[j])
                down[i] = max(down[i], down[j] + a[i]);
        }
    }

    int res = 0;
    forup(i, 0, n)
        // bitonicsum = upsum + downsum - a[i] (counted 2 times)
        res = max(res, up[i] + down[i] - a[i]);
        
    cout << res << el;
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int n; cin >> n;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        bitonic(a, n);    
    }
}