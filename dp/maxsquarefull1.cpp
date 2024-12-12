#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA05019
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(z, x, y) cout << a[z] << " "
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
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // largest square ending at (i, j)
        forup(i, 1, n + 1) 
            forup(j, 1, m + 1)
                cin >> a[i][j];

        int res = 0;        
        forup(i, 1, n + 1)
        {
            forup(j, 1, m + 1)
            {
                if (a[i][j])
                    // For a cell (i, j) to be part of a larger square, 
                    // all three neighboring cells must also be part of square. 
                    // The size of the largest square submatrix ending at (i, j) 
                    // is thus determined by the smallest of these three values. 
                    // Adding 1 accounts for the current cell itself.
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                res = max(res, dp[i][j]);
            }
        }
        // forup(i, 1, n + 1)
        // {
        //     print(dp[i], 1, m + 1);
        //     cout << el;
        // }
        cout << res << el;
    }
}