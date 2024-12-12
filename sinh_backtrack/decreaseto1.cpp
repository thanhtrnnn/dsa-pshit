#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02041
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
		queue<pair<int, int>> X; 
        X.push({n,0});
		while (!X.empty()) 
        {
			pair<int, int> b = X.front();
			X.pop();
			if (b.first == 1) 
            {
				cout << b.second << endl;
				break;
			}
			if (b.first % 2 == 0)
                X.push({b.first / 2, b.second + 1});
			if (b.first % 3 == 0)
                X.push({b.first / 3, b.second + 1});
			if (b.first > 1)
                X.push({b.first - 1,b.second + 1});
		}
    }
}