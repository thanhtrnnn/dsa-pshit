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

int dp[101][101][101] = {};
int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        int a, b, c; 
        cin >> a >> b >> c;
        string x, y, z;
        cin >> x >> y >> z;

		forup(i, 1, a + 1) 
        {
			forup(j, 1, b + 1) 
            {
				forup(l, 1, c + 1) 
                {
					// if (i == 0 || j == 0 || l == 0)
                    //     dp[i][j][l] = 0;
						if (x[i - 1] == y[j - 1] && x[i - 1] == z[l - 1])
                            dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
						else 
                            dp[i][j][l] = max(dp[i - 1][j][l], 
                                    max(dp[i][j][l - 1], dp[i][j - 1][l]));
					
				}
			}
		}
		cout << dp[a][b][c] << endl;
    }
}