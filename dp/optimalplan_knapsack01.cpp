#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//CTDL_003
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

	int n, k; 
	cin >> n >> k;
	vector<int> weight(n + 1);
	vector<int> value(n + 1);
	for (int i = 1; i <= n; i++) cin >> value[i];
	for (int i = 1; i <= n; i++) cin >> weight[i];
	// max value for i items and weight <= k
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); 

	int fopt;
	vector<int> xopt(n + 1, 0);
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= k; j++) 
		{
			if (j < weight[i])
			// definitely not choose bc item larger than total
				dp[i][j] = dp[i - 1][j];
			else
				// max of not choosing and choosing item i
				dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
		}
	}

	fopt = dp[n][k];
	cout << fopt << endl;
	fordown(i, n, 1)
	{
		if (dp[i][k] != dp[i - 1][k])
		{
			xopt[i] = 1;
			k -= weight[i];
		}
	}
	print(xopt, 1, (int)xopt.size());
}