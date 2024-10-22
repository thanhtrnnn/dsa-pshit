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


int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	forup(i, 0, pow(2, n)) 
    {
		auto s = bitset<20>(i).to_string();
		s = s.substr(20 - n, n);
		if (s[0] == '1' && s[n - 1] == '0' 
                && (int)s.find("11") == -1 && (int)s.find("0000") == -1) 
        {
			for (auto c : s)
                (c == '1') ? cout << '8' : cout << '6';
			cout << el;
		}
	}
}
