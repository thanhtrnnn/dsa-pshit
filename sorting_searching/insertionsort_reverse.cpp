#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06029
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

    int n; cin >> n;
	int M[1000];
	vector<vector<int>> N;
	for (int i = 0; i < n; i++) cin >> M[i];
	for (int i = 1; i <= n; i++) 
    {
		sort(M, M + i);
		vector<int> X;
		for (int l = 0; l < i; l++)
            X.push_back(M[l]);
		N.push_back(X);
	}

	for (int i = size(N) - 1; i >= 0; i--) 
    {
		cout << "Buoc " << i << ": ";
		for (int j = 0; j < size(N[i]); j++)
			cout << N[i][j] << " ";
		cout << endl;
	}
}