#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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
        int n; cin >> n;
        vector<ll> a(n);
        forup(i, 0, n) 
        {
            cin >> a[i];
            a[i] *= a[i];
        }
        sort(all(a));
        bool res = false;
        fordown(i, n - 1, 2)
        {
            int l = 0, r = i - 1;
            while (l < r) 
            {
                if (a[l] + a[r] == a[i])
                {
                    res = true;
                    break;
                }
                else if (a[l] + a[r] < a[i]) 
                    l++;
                else 
                    r--;
            }
        }

        cout << (res ? "YES\n" : "NO\n");
    }
}