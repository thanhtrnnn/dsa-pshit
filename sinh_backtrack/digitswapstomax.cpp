#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA02007
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

int res, k;
void backtrack(string s, int pos, int swaps)
{
    res = max(res, stoi(s));
    if (swaps == k)
        return;
    forup(i, 0, (int)s.length()) //duyet tat ca
    {
        forup(j, pos, (int)s.length()) //swap voi tat ca
        {
            swap(s[i], s[j]);
            backtrack(s, j + 1, swaps + 1);
            swap(s[i], s[j]);
        }
    }
}

void Try(string s, int swapsleft) 
{
	if (swapsleft == 0)
        return;
	forup(i, 0, (int)s.length())
    {
		forup(j, i + 1, (int)s.length()) 
        {
			if (s[i] < s[j]) 
            {
				swap(s[i], s[j]);
				res = max(res, stoi(s));
				Try(s, swapsleft - 1);
				swap(s[i], s[j]);
			}
		}
	}
}

int main()
{
    fileio();
    ios::sync_with_stdio(false); cin.tie(0);

    tests()
    {
        cin >> k;
        string s; cin >> s;
        res = stoi(s);
        // Try(s, k);
        backtrack(s, 0, 0);
        cout << res << el;
    }
}