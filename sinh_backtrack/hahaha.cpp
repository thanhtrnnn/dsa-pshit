#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA01019
#define forup(i, a, b)      for (int i = (a); i < (b); i++)
#define fordown(i, l, r)    for (int i = l; i >= r; i--)
#define print(a, x, y)      forup(i, x, y) cout << a[i] << " "
#define all(M)              M.begin(), M.end()
#define tests()             int t; cin >> t; while (t--)
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
        forup(i, 0, pow(2, n)) 
        {
            // generate binary form of i
			auto s = bitset<20>(i).to_string();
            // create a substr from 20 - n, length n
			s = s.substr(20 - n, n);
            // validation
			if ((int)s.find("11") == -1 && s[0] == '1' && s[n - 1] == '0') 
            {
				for (auto c : s)
                    (c == '1') ? cout << 'H' : cout << 'A';
				cout << el;
			}
		}
    }
}