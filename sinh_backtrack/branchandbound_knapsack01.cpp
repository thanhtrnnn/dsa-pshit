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

int n, w;
vector<int> weight(10), value(10), xopt;
void backtrack(int i, int n, vector<int> &a, double &fopt)
{
	if (i == n + 1)
	{
		double currval = 0, currweight = 0;
		forup(z, 1, n + 1)
		{
			if (a[z] == 1)
			{
				currweight += weight[z];
				if (currweight > w)
					return;
				currval += a[z] * value[z];
			}
		}
		if (fopt < currval)
		{
			fopt = currval;
			xopt = a;
		}
		return;
	}
    for (int j = 0; j <= 1; j++)
    {
        a.push_back(j);
		backtrack(i + 1, n, a, fopt);
		a.pop_back();
    }
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> weight[i];
	for (int i = 1; i <= n; i++) cin >> value[i];

	// max value for i items and weight <= k
	double fopt = 0;
	vector<int> a(1, 0);
    backtrack(1, n, a, fopt);
	cout << fixed << setprecision(1.0) << fopt << el;
	print(xopt, 1, n + 1);
}