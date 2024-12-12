#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//idhere
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

    tests()
    {
        int n; cin >> n;
		int M[1000];
		int gt = 1;
		vector<vector<int>> N;
		for (int i = 0; i < n; i++) cin >> M[i];
		for (int i = 1; i < n; i++) 
        {
			int k = 0;
			for (int j = 0; j < n - 1; j++) 
            {
				if (M[j] > M[j + 1]) 
                {
					swap(M[j], M[j + 1]);
					k++;
				}
			}
			if (k) 
            {
				vector<int> X;
				for (int l = 0; l < n; l++)
                    X.push_back(M[l]);
				N.push_back(X);
			}
			
		}
		for (int i = size(N) - 1; i >= 0; i--) 
        {
			cout << "Buoc " << i + 1 << ": ";
			for (int j = 0; j < n; j++)
				cout << N[i][j] << " ";
			cout << endl;
		}
    }
}