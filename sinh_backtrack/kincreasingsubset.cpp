#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02038
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
		int n, k; 
        cin >> n >> k;
		vector<int> M(n); 
        forup(i, 0, n) cin >> M[i];
		sort(all(M));
		string s = string(k, '0') + string(n - k, '1');
		do {
			forup(i, 0, n)
                if (s[i] == '0')
                    cout << M[i] << " ";
			cout << endl;
		} 
        while (next_permutation(all(s)));
    }
}