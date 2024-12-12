#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA06031
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
		int n, k; cin >> n >> k;
		vector<int> M;
		for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            M.push_back(x);
        }
        
		multiset<int> X;
		for (int i = 0; i < k; i++)
            X.insert(M[i]);
		cout << *X.rbegin() << " ";
		for (int i = k; i < n; i++) 
        {
			X.erase(X.find(M[i - k]));
			X.insert(M[i]);
			cout << *X.rbegin() << " ";
		}
		cout << el;
    }
}