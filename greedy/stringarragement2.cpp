#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA03013
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
        int d;
        string s;
        cin >> d >> s;
        map<char, int> mp;
        bool ok = true;
        for (char x : s) 
            mp[x]++;
        for (auto it : mp)  
        {
            if (it.second > (int)(s.length() - 1) / d + 1)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "1" : "-1") << endl;
    }
}