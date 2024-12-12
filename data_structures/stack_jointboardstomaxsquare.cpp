#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA07024
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
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        stack<int> pot;
        int res = 0, i = 0;
        while (i < n)
        {
            // ascending stack
            if (pot.empty() || a[pot.top()] < a[i])
            {   
                pot.push(i);
                i++;
            }
            else {
                int cur = pot.top(); // the rectangle ending with cur
                pot.pop();
                if (pot.empty())
                {
                    // i is width from 0, a[cur] is height
                    if (a[cur] <= i)
                        res = max(res, a[cur]);
                }
                // i - top - 1 is width from top to i - 1
                else if (a[cur] <= i - pot.top() - 1) {
                    cout << i << ' ' << pot.top() << ' ' << a[cur] << el;
                    res = max(res, a[cur]);
                }
            }
        }

        while (!pot.empty())
        {
            int cur = pot.top();
            pot.pop();
            if (pot.empty())
            {
                if (a[cur] <= i)
                    res = max(res, a[cur]);
            }
            else if (a[cur] <= i - pot.top() - 1)
                res = max(res, a[cur]);
        }

        cout << res << el;        
    }
}