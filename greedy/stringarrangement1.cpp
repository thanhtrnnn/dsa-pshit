#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//DSA03012
#define forloop(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", "r", stdin);
    freopen("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        // old solution, got WA
        // int pairs = 0, dups = 0;
        // forloop(i, 0, (int)s.length()-1)
        // {
        //     if (s[i] == s[i+1]) dups++;
        //     pairs++;
        // }
        // cout << (dups <= pairs/2) << endl;

        map<char, int> mp;
        bool ok = true;
        for (char x : s) mp[x]++;
        for (auto it : mp)  
        {
            // max freq of a char = (int) (s.length() + 1) / 2
            if (it.second * 2 - 1 > (int)s.length())
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "1" : "-1") << endl;
    }
}