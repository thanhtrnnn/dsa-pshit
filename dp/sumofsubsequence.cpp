#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
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

    int t; cin >> t;
    while(t--)
    {
        int n, s; 
        cin >> n >> s;
        vector<int> a(n);
        forup(i, 0, n) cin >> a[i];
        vector<bool> dp(s + 1, 0);
        dp[0] = true;
        forup(i, 0, n)
        {
            fordown(j, s, a[i])
            {
                if (dp[j - a[i]])
                    dp[j] = 1;
            }
        }
        
        cout << (dp[s] ? "YES" : "NO") << el;
    }
}