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

    tests()
    {
        string s; cin >> s;
        int res = 0;
        while ((int)s.length())
        {
            int pos = s.find("()");
            if (pos != -1)
                s.erase(pos, 2);
            else {
                if (s[0] == ')')
                {
                    s[0] = '(';
                    res++;
                }
                if (s[(int)s.length() - 1] == '(')
                {
                    s[(int)s.length() - 1] = ')';
                    res++;
                }
            }
        }
        cout << res << el;
    }
}