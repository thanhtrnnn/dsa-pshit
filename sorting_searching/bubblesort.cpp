#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06026
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

    int n; cin >> n;
    vector<int> a(n);
    forup(i, 0, n) cin >> a[i];
    int cnt = 1;
	forup(i, 0, n)
    {
		int swaps = 0;
		forup(j, 0, n - i - 1)
        {
			if (a[j] > a[j + 1])
            {
				swap(a[j], a[j + 1]);
				swaps++;
			}
		}
		if (swaps == 0) 
            break;

		cout << "Buoc " << cnt << ": ";
		print(a, 0, n);
		cnt++;
		cout << el;
	}

	if (cnt == 1)
    {
		cout << "Buoc " << cnt << ": ";
		print(a, 0, n);
	}
}